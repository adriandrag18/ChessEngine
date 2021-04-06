// Created by adrian on 17.06.2020.
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

#include <stdio.h>
#include "../headers/struct.h"
#include "../headers/init.h"
#include "../headers/data.h"
#include "../headers/eval.h"
#include "../headers/generator.h"

void printFiles() {
    for (int i = 0; i < 120; ++i) {
        if (i % 10 == 0)
            printf("\n");
        printf("%5d", files[i]);
    }
    printf("\n");
}

void printRanks() {
    for (int i = 0; i < 120; ++i) {
        if (i % 10 == 0)
            printf("\n");
        printf("%5d", ranks[i]);
    }
    printf("\n");
}

void print120() {
    printf("\n");
    for (int i = 11; i >= 0; --i) {
        for (int j = 0; j < 10; ++j)
            printf("%5d", sq120ToSq64[i * 10 + j]);
        printf("\n");
    }
    printf("\n");
}

void print64() {
    printf("\n");
    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j)
            printf("%5d", sq64ToSq120[i * 8 + j]);
        printf("\n");
    }
    printf("\n");
}

char *prSq(const int sq) {
    static char sqStr[3];
    sprintf(sqStr, "%c%c", 'a' + files[sq], '1' + ranks[sq]);
    return sqStr;
}

char *prMove(U32 move) {
    static char moveStr[6];
    sprintf(moveStr, "%c%c", 'a' + files[FROM(move)], '1' + ranks[FROM(move)]);
    sprintf(moveStr + 2, "%c%c", 'a' + files[TO(move)], '1' + ranks[TO(move)]);

    U32 promoted = PROMOTED(move);
    if (promoted) {
        char promotedChar = 'q';
        if (isKn[promoted]) promotedChar = 'n';
        if (promoted == wB || promoted == bB) promotedChar = 'b';
        if (promoted == wR || promoted == bR) promotedChar = 'r';
        sprintf(moveStr + 4, "%c", promotedChar);
    }

    return moveStr;
}

void printMove(U32 move) {
    printf("From: %s  To: %s\nCaptured: %u  Promoted: %u\n",
           prSq(FROM(move)), prSq(TO(move)), CAPTURED(move), PROMOTED(move));
    printf("Castle: %u  PawnStart: %u  EnPass: %u", move & CASTLE_FLAG, move & PAWN_START_FLAG, move & EN_PASSANT_FLAG);
}

void printBitBoard(U64 bb) {
    U64 sq, sq64;

    for (int rank = RANK_8; rank >= RANK_1; --rank) {
        for (int file = A; file <= H; ++file) {
            sq = FR2SQ(file, rank);
            sq64 = SQ64(sq);
            if ((1ULL << sq64) & bb)
                printf("X");
            else
                printf("_");
        }
        printf("\n");
    }
    printf("\n");
}

const char piecesChar[] = "..wPwNwBwRwQwKbPbNbBbRbQbK";

void printBoard(const Board *pos) {
    int sq, file, rank, piece;

    printf("\n");
    for (rank = RANK_8; rank >= RANK_1; rank--) {
        printf("%d  ", rank + 1);
        for (file = A; file <= H; file++) {
            sq = FR2SQ(file, rank);
            piece = pos->pieces[sq];
            printf(" %c%c ", piecesChar[2 * piece], piecesChar[2 * piece + 1]);
        }
        printf("\n");
    }

    printf("\n   ");
    for (file = A; file <= H; file++) {
        printf("  %c ", 'a' + file);
    }

    printf("\n");
    printf("side: %c\n", sideChar[pos->side]);
    printf("Ply: %d\n", pos->ply);
    if (pos->enPas != NO_SQ)
        printf("enPas: %s\n", prSq(pos->enPas));
    else
        printf("enPas: NO_SQ\n");
    printf("castle: %c%c%c%c\n",
           pos->castlePerm & WKCA ? 'K' : '-',
           pos->castlePerm & WQCA ? 'Q' : '-',
           pos->castlePerm & BKCA ? 'k' : '-',
           pos->castlePerm & BQCA ? 'q' : '-');
    printf("PosKey: %llX\n", pos->hashKey);
#ifdef DEBUG
    printf("Evaluation: %d\n", evalPosition(pos));
#endif
}

void showSqAttackedBySide(const int side, const Board *pos) {
    int rank, file, sq;

    printf("\nSquares attacked by: %c\n", sideChar[side]);
    for (rank = RANK_8; rank >= RANK_1; --rank) {
        for (file = A; file <= H; ++file) {
            sq = FR2SQ(file, rank);
            if (isSqAttacked(sq, side, pos))
                printf("X ");
            else
                printf("_ ");
        }
        printf("\n");
    }
    printf("\n");
}

#pragma clang diagnostic pop
