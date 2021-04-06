// Created by adrian on 17.06.2020.

#include <printf.h>
#include "../headers/struct.h"
#include "../headers/init.h"
#include "../headers/data.h"

int sqOnBoard(const int sq) {
    return files[sq] != OFFBOARD;
}

int sideValid(const int side) {
    return (side == WHITE || side == BLACK);
}

int fileRankValid(const int fr) {
    return (fr >= 0 && fr <= 7);
}

int pieceValidOrEmpty(const int pce) {
    return (pce >= EMPTY && pce <= bK);
}

int pieceValid(const int pce) {
    return (pce >= wP && pce <= bK);
}

static const int bitTable[64] = {
        63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2, 51, 21, 43, 45, 10, 18, 47, 1, 54,
        9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52, 26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38,
        28, 58, 20, 37, 17, 36, 8
};

int popBit(U64 *bb) {
    U64 b = *bb ^(*bb - 1);  // => 0000...0111...1111 the last 0 is the in place of the first 1 form bb
    *bb &= (*bb - 1);  // => bb without the last 1
    U32 fold = (b & 0xffffffff) ^(b >> (U8) 0x20);
    /* 0000...0001...1111 if the last 1 was in the last 32 bits
     * 1111...1110...0000 it was in the first 32 bits
     * the last digit before the change (0 to 1 or 1 to 0) is the in place of the first 1 form bb
     */
    fold = (fold * 0x783a9b23) >> (U8) 26;  // some type of hash
    return bitTable[fold];
}

int countBits(U64 bb) {
    int num = 0;
    for (; bb; bb &= bb - 1)
        num++;
    return num;
}

static void resetBoard(Board *pos) {
    for (int i = 0; i < 120; ++i)
        pos->pieces[i] = OFFBOARD;

    for (int j = 0; j < 64; ++j)
        pos->pieces[SQ120(j)] = EMPTY;

    for (int k = WHITE; k <= BLACK; ++k) {
        pos->bigPieces[k] = 0;
        pos->majPieces[k] = 0;
        pos->minPieces[k] = 0;
        pos->material[k] = 0;
    }

    for (int l = 0; l < 3; ++l)
        pos->pawns[l] = 0;

    for (int piece = EMPTY; piece <= bK; ++piece)
        pos->pcsNum[piece] = 0;

    for (int piece = EMPTY; piece <= bK; ++piece) {
        for (int pceNum = 0; pceNum < 9; ++pceNum)
            pos->pcsList[piece][pceNum] = OFFBOARD;
    }

    pos->side = BOTH;
    pos->fiftyMoves = 0;
    pos->enPas = NO_SQ;
    pos->castlePerm = 0;

    pos->ply = 0;
    pos->searchPly = 0;

    pos->hashKey = 0;
}

static void updateListsMaterials(Board *pos) {
    for (int sq = 0; sq < 120; ++sq) {
        int piece = pos->pieces[sq];

        if (piece != OFFBOARD && piece != EMPTY) {
            int side = pieceSide[piece];

            if (isPieceBig[piece]) pos->bigPieces[side]++;
            if (isPieceMaj[piece]) pos->majPieces[side]++;
            if (isPieceMin[piece]) pos->minPieces[side]++;

            pos->material[side] += pieceVal[piece];
            pos->pcsList[piece][pos->pcsNum[piece]++] = sq;

            if (isPawn[piece]) {
                SET(pos->pawns[side], SQ64(sq));
                SET(pos->pawns[BOTH], SQ64(sq));
            }
        }
    }
}

U64 generateHashKey(const Board *pos) {
    U64 finalKey = 0;
    for (int sq = 0; sq < 120; ++sq) {
        int piece = pos->pieces[sq];
        if (piece != OFFBOARD && piece != EMPTY) {
            ASSERT(pieceValid(piece))
            finalKey ^= pieceKeys[piece][sq];
        }
    }

    if (pos->side == WHITE)
        finalKey ^= sideKey;

    if (pos->enPas != NO_SQ) {
        ASSERT(pos->enPas >= 0 && pos->enPas < 120)
        finalKey ^= pieceKeys[EMPTY][pos->enPas];
    }

    ASSERT(pos->castlePerm <= 15)
    finalKey ^= castleKeys[pos->castlePerm];

    return finalKey;
}

#define VERIFY(n)                   \
if (!(n)) {                         \
    printf("\nCheckBoard failed at" \
    " %s line %d\n", #n, __LINE__); \
    return false;                   \
}

int checkBoard(const Board *pos) {
    int tPcsNum[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int tBigPcs[13] = {0, 0};
    int tMajPcs[13] = {0, 0};
    int tMinPcs[13] = {0, 0};
    int tMaterial[13] = {0, 0};
    int sq64, sq120, tPiece, side, pCount, tNum;
    U64 tPawns[3] = {0, 0, 0};

    tPawns[WHITE] = pos->pawns[WHITE];
    tPawns[BLACK] = pos->pawns[BLACK];
    tPawns[BOTH] = pos->pawns[BOTH];

    for (tPiece = wP; tPiece <= bK; tPiece++) {
        for (tNum = 0; tNum < pos->pcsNum[tPiece]; tNum++) {
            sq120 = pos->pcsList[tPiece][tNum];
            VERIFY(pos->pieces[sq120] == tPiece)
        }
    }
    for (sq64 = 0; sq64 < 64; sq64++) {
        sq120 = SQ120(sq64);
        tPiece = pos->pieces[sq120];
        tPcsNum[tPiece]++;
        side = pieceSide[tPiece];
        if (isPieceBig[tPiece]) tBigPcs[side]++;
        if (isPieceMaj[tPiece]) tMajPcs[side]++;
        if (isPieceMin[tPiece]) tMinPcs[side]++;
        tMaterial[side] += pieceVal[tPiece];
    }
    for (tPiece = wP; tPiece <= bK; tPiece++) {
        VERIFY(tPcsNum[tPiece] == pos->pcsNum[tPiece])
    }

    pCount = countBits(tPawns[WHITE]);
    VERIFY(pCount == pos->pcsNum[wP])
    pCount = countBits(tPawns[BLACK]);
    VERIFY(pCount == pos->pcsNum[bP])
    pCount = countBits(tPawns[BOTH]);
    VERIFY(pCount == pos->pcsNum[wP] + pos->pcsNum[bP])

    while (tPawns[WHITE]) {
        sq64 = popBit(&tPawns[WHITE]);
        VERIFY(pos->pieces[SQ120(sq64)] == wP)
    }
    while (tPawns[BLACK]) {
        sq64 = popBit(&tPawns[BLACK]);
        VERIFY(pos->pieces[SQ120(sq64)] == bP)
    }
    while (tPawns[BOTH]) {
        sq64 = popBit(&tPawns[BOTH]);
        VERIFY(pos->pieces[SQ120(sq64)] == bP || pos->pieces[SQ120(sq64)] == wP)
    }
    VERIFY(tMaterial[WHITE] == pos->material[WHITE] && tMaterial[BLACK] == pos->material[BLACK])
    VERIFY(tMinPcs[WHITE] == pos->minPieces[WHITE] && tMinPcs[BLACK] == pos->minPieces[BLACK])
    VERIFY(tMajPcs[WHITE] == pos->majPieces[WHITE] && tMajPcs[BLACK] == pos->majPieces[BLACK])
    VERIFY(tBigPcs[WHITE] == pos->bigPieces[WHITE] && tBigPcs[BLACK] == pos->bigPieces[BLACK])
    VERIFY(pos->side == WHITE || pos->side == BLACK)
    VERIFY(generateHashKey(pos) == pos->hashKey)

    return true;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

int parseFEN(const char *fen, Board *pos) {
    ASSERT(fen != NULL)
    ASSERT(pos != NULL)

    int rank = RANK_8, file = A;
    int piece, count, sq64, sq120;

    resetBoard(pos);

    while ((rank >= RANK_1) && *fen) {
        count = 1;
        switch (*fen) {
            case 'p':
                piece = bP;
                break;
            case 'n':
                piece = bN;
                break;
            case 'b':
                piece = bB;
                break;
            case 'r':
                piece = bR;
                break;
            case 'q':
                piece = bQ;
                break;
            case 'k':
                piece = bK;
                break;
            case 'P':
                piece = wP;
                break;
            case 'N':
                piece = wN;
                break;
            case 'B':
                piece = wB;
                break;
            case 'R':
                piece = wR;
                break;
            case 'Q':
                piece = wQ;
                break;
            case 'K':
                piece = wK;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                piece = EMPTY;
                count = *fen - '0';
                break;
            case '/':
            case ' ':
                rank--;
                file = A;
                fen++;
                continue;
            default:
                printf("FEN Error at characters");
                return -1;
        }
        for (int i = 0; i < count; ++i) {
            sq64 = rank * 8 + file;
            sq120 = SQ120(sq64);
            pos->pieces[sq120] = piece;
            file++;
        }
        fen++;
    }

    if (*fen != 'w' && *fen != 'b') {
        printf("FEN Error at side");
        return -1;
    }

    pos->side = (*fen == 'w') ? WHITE : BLACK;
    fen += 2;

    for (int j = 0; j < 4; ++j) {
        if (*fen == '-') {
            fen++;
            break;
        }
        if (*fen == ' ')
            break;
        switch (*fen) {
            case 'K':
                pos->castlePerm |= WKCA;
                break;
            case 'Q':
                pos->castlePerm |= WQCA;
                break;
            case 'k':
                pos->castlePerm |= BKCA;
                break;
            case 'q':
                pos->castlePerm |= BQCA;
                break;
            default:
                break;
        }
        fen++;
    }
    fen++;
    ASSERT(pos->castlePerm >= 0 && pos->castlePerm <= 15)

    if (*fen != '-') {
        file = fen[0] - 'a';
        rank = fen[1] - '1';
        fen += 2;
        if (file < A || file > H || rank < RANK_1 || rank > RANK_8) {
            printf("FEN Error at enPass square file: %c rank: %c", fen[1], fen[0]);
            return -1;
        }
        pos->enPas = FR2SQ(file, rank);
    }
    fen++;
    sscanf(fen, "%d %d", &(pos->fiftyMoves), &(pos->ply));
    pos->ply = 2 * (pos->ply - 1) + pos->side;

    pos->hashKey = generateHashKey(pos);
    updateListsMaterials(pos);

    return 1;
}

char *getFEN(const Board *pos) {
    static char fen[90];
    int piece, i = 0;
    for (int rank = RANK_8; rank >= RANK_1; --rank) {
        int count = 0;
        for (int file = A; file <= H; ++file) {
            piece = pos->pieces[FR2SQ(file, rank)];
            if (piece == EMPTY) {
                count++;
                continue;
            } else {
                if (count)
                    fen[i++] = '0' + count;
                fen[i++] = pcsChar[piece];
                count = 0;
            }
        }
        if (count)
            fen[i++] = '0' + count;
        fen[i++] = '/';
    }
    i--;
    fen[i++] = ' ';
    fen[i++] = sideChar[pos->side];
    fen[i++] = ' ';

    if (pos->castlePerm & WKCA)
        fen[i++] = 'K';
    if (pos->castlePerm & WQCA)
        fen[i++] = 'Q';
    if (pos->castlePerm & BKCA)
        fen[i++] = 'k';
    if (pos->castlePerm & BQCA)
        fen[i++] = 'q';
    if (fen[i - 1] == ' ')
        fen[i++] = '-';
    fen[i++] = ' ';

    if (pos->enPas == NO_SQ)
        fen[i++] = '-';
    else {
        fen[i++] = 'a' + files[pos->enPas];
        fen[i++] = '1' + ranks[pos->enPas];
    }
    sprintf(fen + i, " %d %d", pos->fiftyMoves, pos->ply / 2 + 1);
    return fen;
}

#pragma clang diagnostic pop