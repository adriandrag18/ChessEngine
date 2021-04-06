// Created by adrian on 17.06.2020.
#include "../headers/board.h"
#include "../headers/data.h"
#include "../headers/init.h"
#include "../headers/generator.h"

#ifdef DEBUG

#include "../headers/print.h"

#endif

#define HASH_PCE(pos, pce, sq) ( ((pos)->hashKey) ^= (pieceKeys[(pce)][(sq)]) )
#define HASH_CASTLE(pos) ( ((pos)->hashKey) ^= (castleKeys[((pos)->castlePerm)]) )
#define HASH_SIDE(pos) ( ((pos)->hashKey) ^= (sideKey))
#define HASH_EN_PASSANT(pos) ( ((pos)->hashKey) ^= (pieceKeys[EMPTY][((pos)->enPas)]) )

void clearPiece(Board *pos, const int sq) {
    ASSERT(sqOnBoard(sq))
    int pce = pos->pieces[sq];
    ASSERT(pieceValid(pce))
    int side = pieceSide[pce];

    HASH_PCE(pos, pce, sq);
    pos->pieces[sq] = EMPTY;
    pos->material[side] -= pieceVal[pce];

    if (isPieceBig[pce]) {
        pos->bigPieces[side]--;
        if (isPieceMaj[pce]) {
            pos->majPieces[side]--;
        } else {
            pos->minPieces[side]--;
        }
    } else {
        CLEAR(pos->pawns[side], SQ64(sq));
        CLEAR(pos->pawns[BOTH], SQ64(sq));
    }

    int pceNum;
    for (pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        if (pos->pcsList[pce][pceNum] == sq)
            break;
    }
    ASSERT(pceNum != pos->pcsNum[pce])
    pos->pcsNum[pce]--;
    pos->pcsList[pce][pceNum] = pos->pcsList[pce][pos->pcsNum[pce]];
}

void addPiece(Board *pos, const int pce, const int sq) {
    ASSERT(pieceValid(pce))
    ASSERT(sqOnBoard(sq))

    int side = pieceSide[pce];

    HASH_PCE(pos, pce, sq);
    pos->pieces[sq] = pce;
    pos->material[side] += pieceVal[pce];

    if (isPieceBig[pce]) {
        pos->bigPieces[side]++;
        if (isPieceMaj[pce]) {
            pos->majPieces[side]++;
        } else {
            pos->minPieces[side]++;
        }
    } else {
        SET(pos->pawns[side], SQ64(sq));
        SET(pos->pawns[BOTH], SQ64(sq));
    }
    pos->pcsList[pce][pos->pcsNum[pce]] = sq;
    pos->pcsNum[pce]++;
}

void movePiece(Board *pos, const int from, const int to) {
    ASSERT(sqOnBoard(from))
    ASSERT(sqOnBoard(to))

    int pce = pos->pieces[from], side = pieceSide[pce];

    ASSERT(pieceValid(pce))
    ASSERT(sideValid(side))

    HASH_PCE(pos, pce, from);
    HASH_PCE(pos, pce, to);

    pos->pieces[from] = EMPTY;
    pos->pieces[to] = pce;
    if (isPawn[pce]) {
        CLEAR(pos->pawns[side], SQ64(from));
        CLEAR(pos->pawns[BOTH], SQ64(from));
        SET(pos->pawns[side], SQ64(to));
        SET(pos->pawns[BOTH], SQ64(to));
    }

    int pceNum;
    for (pceNum = 0; pceNum < pos->pcsNum[pce]; pceNum++) {
        if (pos->pcsList[pce][pceNum] == from) {
            pos->pcsList[pce][pceNum] = to;
            break;
        }
    }
    ASSERT(pceNum != pos->pcsNum[pce])
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

void undoMove(Board *pos) {
    ASSERT(checkBoard(pos))
    pos->ply--;
    pos->searchPly--;

    int move = pos->history[pos->ply].move, from = FROM(move), to = TO(move);
    ASSERT(sqOnBoard(from))
    ASSERT(sqOnBoard(to))

    int captured = CAPTURED(move), promoted = PROMOTED(move);
    ASSERT(pieceValidOrEmpty(captured))
    ASSERT(pieceValidOrEmpty(promoted))

    pos->side ^= 1;
    HASH_SIDE(pos);

    if (promoted != EMPTY) {
        clearPiece(pos, to);
        addPiece(pos, pos->side == WHITE ? wP : bP, to);
    }

    movePiece(pos, to, from);

    if (captured != EMPTY) {
        addPiece(pos, captured, to);
    }

    if (pos->enPas != NO_SQ)
        HASH_EN_PASSANT(pos);
    HASH_CASTLE(pos);

    pos->fiftyMoves = pos->history[pos->ply].fiftyMoves;
    pos->enPas = pos->history[pos->ply].enPas;
    pos->castlePerm = pos->history[pos->ply].castlePerm;

    if (pos->enPas != NO_SQ)
        HASH_EN_PASSANT(pos);
    HASH_CASTLE(pos);

    if (move & EN_PASSANT_FLAG) {
        if (pos->side == WHITE)
            addPiece(pos, bP, to - 10);
        else
            addPiece(pos, wP, to + 10);
    } else if (move & CASTLE_FLAG) {
        switch (to) {
            case C1:
                movePiece(pos, D1, A1);
                break;
            case G1:
                movePiece(pos, F1, H1);
                break;
            case C8:
                movePiece(pos, D8, A8);
                break;
            case G8:
                movePiece(pos, F8, H1);
                break;
            default:
                ASSERT(false)
        }
    }

    ASSERT(checkBoard(pos))
}

int makeMove(Board *pos, int move) {
    ASSERT(checkBoard(pos))

    int from = FROM(move), to = TO(move), captured = CAPTURED(move), side = pos->side;
    ASSERT(sqOnBoard(from))
    ASSERT(sqOnBoard(to))
    ASSERT(pieceValidOrEmpty(captured))
    ASSERT(sideValid(side))

    int pce = pos->pieces[from], promoted = PROMOTED(move);
    ASSERT(pieceValid(pce))
    ASSERT(pieceValidOrEmpty(promoted) && !isPawn[promoted])

    pos->history[pos->ply].hashKey = pos->hashKey;

    if (move & EN_PASSANT_FLAG) {
        clearPiece(pos, side == WHITE ? to - 10 : to + 10);
    } else if (move & CASTLE_FLAG) {
        switch (to) {
            case C1:
                movePiece(pos, A1, D1);
                break;
            case G1:
                movePiece(pos, H1, F1);
                break;
            case C8:
                movePiece(pos, A8, D8);
                break;
            case G8:
                movePiece(pos, H8, F8);
                break;
            default:
                ASSERT(false)
        }
    }

    if (pos->enPas != NO_SQ)
        HASH_EN_PASSANT(pos);
    HASH_CASTLE(pos);

    pos->history[pos->ply].move = move;
    pos->history[pos->ply].fiftyMoves = pos->fiftyMoves;
    pos->history[pos->ply].enPas = pos->enPas;
    pos->history[pos->ply].castlePerm = pos->castlePerm;

    pos->castlePerm &= castlePerm[from];
    pos->castlePerm &= castlePerm[to];
    HASH_CASTLE(pos);

    pos->enPas = NO_SQ;

    if (isPawn[pce]) {
        pos->fiftyMoves = 0;
        if (move & PAWN_START_FLAG) {
            pos->enPas = side == WHITE ? to - 10 : to + 10;
            ASSERT(ranks[pos->enPas] == (side == WHITE ? RANK_3 : RANK_6))
            HASH_EN_PASSANT(pos);
        }
    }

    if (captured != EMPTY) {
        clearPiece(pos, to);
        pos->fiftyMoves = 0;
    }

    pos->ply++;
    pos->searchPly++;

    movePiece(pos, from, to);

    if (promoted != EMPTY) {
        clearPiece(pos, to);
        addPiece(pos, promoted, to);
    }

    pos->side ^= 1;
    HASH_SIDE(pos);

    ASSERT(checkBoard(pos))

    if (isSqAttacked(pos->pcsList[side == WHITE ? wK : bK][0], pos->side, pos)) {
        undoMove(pos);
        return false;
    }
    return true;
}

#pragma clang diagnostic pop
