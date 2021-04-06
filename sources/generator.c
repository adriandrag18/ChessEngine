// Created by adrian on 17.06.2020.

#include "../headers/struct.h"
#include "../headers/board.h"
#include "../headers/data.h"
#include "../headers/init.h"

#ifdef DEBUG

#include "../headers/print.h"

#endif
const int knDir[8] = {-8, -19, -21, -12, 8, 19, 21, 12};
const int rkDir[4] = {-1, -10, 1, 10};
const int biDir[4] = {-9, -11, 11, 9};
const int kiDir[8] = {-1, -10, 1, 10, -9, -11, 11, 9};
static const int loopSlidePce[8] = {wB, wR, wQ, bB, bR, bQ};
static const int numSliderPce = 3;
static const int numNonSliderPce = 2;
static const int loopNonSlidePce[6] = {wN, wK, bN, bK};
static const int numDir[13] = {0, 0, 8, 4, 4, 8, 8, 0, 8, 4, 4, 8, 8};
static const int pceDir[13][8] = {
        {0,  0,   0,   0,   0,  0,   0},
        {0,  0,   0,   0,   0,  0,   0},
        {-8, -19, -21, -12, 8,  19,  21, 12},
        {-9, -11, 11,  9,   0,  0,   0,  0},
        {-1, -10, 1,   10,  0,  0,   0,  0},
        {-1, -10, 1,   10,  -9, -11, 11, 9},
        {-1, -10, 1,   10,  -9, -11, 11, 9},
        {0,  0,   0,   0,   0,  0,   0},
        {-8, -19, -21, -12, 8,  19,  21, 12},
        {-9, -11, 11,  9,   0,  0,   0,  0},
        {-1, -10, 1,   10,  0,  0,   0,  0},
        {-1, -10, 1,   10,  -9, -11, 11, 9},
        {-1, -10, 1,   10,  -9, -11, 11, 9}};

int isSqAttacked(U32 sq, U32 attackingSide, const Board *pos) {
    ASSERT(sqOnBoard(sq))
    ASSERT(sideValid(attackingSide))
    ASSERT(checkBoard(pos))
    U32 piece, tSq, dir;

    if(attackingSide == WHITE) {
        if(pos->pieces[sq - 11] == wP || pos->pieces[sq - 9] == wP)
            return true;
    } else {
        if(pos->pieces[sq + 11] == bP || pos->pieces[sq + 9] == bP)
            return true;
    }

    for (int i = 0; i < numDir[wN]; ++i) {
        piece = pos->pieces[sq + knDir[i]];
        if (piece != OFFBOARD && isKn[piece] && pieceSide[piece] == attackingSide)
            return true;
    }

    for (int i = 0; i < numDir[wK]; ++i) {
        piece = pos->pieces[sq + kiDir[i]];
        if (piece != OFFBOARD && isKi[piece] && pieceSide[piece] == attackingSide)
            return true;
    }

    for (int j = 0; j < numDir[wR]; ++j) {
        dir = rkDir[j];
        for (tSq = sq + dir, piece = pos->pieces[tSq]; piece != OFFBOARD; tSq += dir) {
            piece = pos->pieces[tSq];
            if (piece != EMPTY) {
                if (isRQ[piece] && pieceSide[piece] == attackingSide)
                    return true;
                break;
            }
        }
    }

    for (int j = 0; j < numDir[wB]; ++j) {
        dir = biDir[j];
        for (tSq = sq + dir, piece = pos->pieces[tSq]; piece != OFFBOARD; tSq += dir) {
            piece = pos->pieces[tSq];
            if (piece != EMPTY) {
                if (isBQ[piece] && pieceSide[piece] == attackingSide)
                    return true;
            break;
        }
        }
    }

    return false;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

static void addQuietMove(const Board *pos, int move, Vector *list) {
    list->moves[list->size].move = move;
    list->moves[list->size].score = 0;
    list->size++;
}

static void addCaptureMove(const Board *pos, int move, Vector *list) {
    list->moves[list->size].move = move;
    list->moves[list->size].score = 0;
    list->size++;
}

static void addEnPassantMove(const Board *pos, int move, Vector *list) {
    list->moves[list->size].move = move;
    list->moves[list->size].score = 0;
    list->size++;
}

static void addPawnMove(const Board *pos, const int from, const int to, const int cap, Vector *list) {
    ASSERT(pieceValidOrEmpty(cap))
    ASSERT(sqOnBoard(from))
    ASSERT(sqOnBoard(to))
    int side = pos->side, rank = side == WHITE ? RANK_7 : RANK_2;
    void (*addMove)() = cap == EMPTY ? addCaptureMove : addQuietMove;

    if (ranks[from] == rank) {
        addMove(pos, MOVE(from, to, cap, wQ + 6 * side, 0), list);
        addMove(pos, MOVE(from, to, cap, wR + 6 * side, 0), list);
        addMove(pos, MOVE(from, to, cap, wB + 6 * side, 0), list);
        addMove(pos, MOVE(from, to, cap, wN + 6 * side, 0), list);
    } else {
        addMove(pos, MOVE(from, to, cap, EMPTY, 0), list);
    }
}

void generateAllMoves(const Board *pos, Vector *allMoves) {
    ASSERT(checkBoard(pos))
    int left = 9, right = 11, forward = 10, rank = RANK_2, side = pos->side, tSq;
    allMoves->size = 0;

    if (side == BLACK) {
        left = -9;
        right = -11;
        forward = -10;
        rank = RANK_7;
        if (pos->castlePerm & BKCA) {
            if (pos->pieces[F8] == EMPTY && pos->pieces[G8] == EMPTY) {
                if (!isSqAttacked(E8, WHITE, pos) && !isSqAttacked(F8, WHITE, pos) && !isSqAttacked(G8, WHITE, pos)) {
                    addQuietMove(pos, MOVE(E8, G8, EMPTY, EMPTY, CASTLE_FLAG), allMoves);
//                    printf("%d\n", __LINE__);
                }
            }
        }
        if (pos->castlePerm & BQCA) {
            if (pos->pieces[D8] == EMPTY && pos->pieces[C8] == EMPTY && pos->pieces[B8] == EMPTY) {
                if (!isSqAttacked(E8, WHITE, pos) && !isSqAttacked(D8, WHITE, pos) && !isSqAttacked(C8, WHITE, pos)) {
                    addQuietMove(pos, MOVE(E8, C8, EMPTY, EMPTY, CASTLE_FLAG), allMoves);
//                    printf("%d\n", __LINE__);
                }
            }
        }
    } else {
        if (pos->castlePerm & WKCA) {
            if (pos->pieces[F1] == EMPTY && pos->pieces[G1] == EMPTY) {
                if (!isSqAttacked(E1, BLACK, pos) && !isSqAttacked(F1, BLACK, pos) && !isSqAttacked(G1, BLACK, pos)) {
                    addQuietMove(pos, MOVE(E1, G1, EMPTY, EMPTY, CASTLE_FLAG), allMoves);
//                    printf("%d\n", __LINE__);
                }
            }
        }
        if (pos->castlePerm & WQCA) {
            if (pos->pieces[D1] == EMPTY && pos->pieces[C1] == EMPTY && pos->pieces[B1] == EMPTY) {
                if (!isSqAttacked(E1, BLACK, pos) && !isSqAttacked(D1, BLACK, pos) && !isSqAttacked(C1, BLACK, pos)) {
                    addQuietMove(pos, MOVE(E1, C1, EMPTY, EMPTY, CASTLE_FLAG), allMoves);
//                    printf("%d\n", __LINE__);
                }
            }
        }
    }

    for (int i = numSliderPce * side; i < numSliderPce * (side + 1); i++) {
        int pce = loopSlidePce[i];
        for (int j = 0; j < pos->pcsNum[pce]; j++) {
            int sq = pos->pcsList[pce][j];
            for (int k = 0; k < numDir[pce]; k++) {
                int dir = pceDir[pce][k];
                for (tSq = sq + dir; pos->pieces[tSq] == EMPTY; tSq += dir) {
                    addQuietMove(pos, MOVE(sq, tSq, EMPTY, EMPTY, 0), allMoves);
//                    printf("%d\n", __LINE__);
                }
                if (pos->pieces[tSq] != OFFBOARD && pieceSide[pos->pieces[tSq]] == (side ^ 1)) {
                    addCaptureMove(pos, MOVE(sq, tSq, pos->pieces[tSq], EMPTY, 0), allMoves);
//                    printf("%d\n", __LINE__);
                }
            }
        }
    }

    for (int i = numNonSliderPce * side; i < numNonSliderPce * (side + 1); i++) {
        int pce = loopNonSlidePce[i];
        for (int j = 0; j < pos->pcsNum[pce]; j++) {
            int sq = pos->pcsList[pce][j];
            for (int k = 0; k < numDir[pce]; k++) {
                tSq = sq + pceDir[pce][k];
                if (pos->pieces[tSq] == OFFBOARD)
                    continue;

                if (pieceSide[pos->pieces[tSq]] == (side ^ 1)) {
                    addCaptureMove(pos, MOVE(sq, tSq, pos->pieces[tSq], EMPTY, 0), allMoves);
//                    printf("%d\n", __LINE__);
                } else if (pos->pieces[tSq] == EMPTY) {
                    addQuietMove(pos, MOVE(sq, tSq, EMPTY, EMPTY, 0), allMoves);
//                    printf("%d, %s\n", __LINE__, prMove(MOVE(sq, tSq, EMPTY, EMPTY, 0)));
                }
            }
        }
    }

    int pce = wP + 6 * side;
    for (int i = 0; i < pos->pcsNum[pce]; i++) {
        int sq = pos->pcsList[pce][i];
        if (pos->pieces[sq + forward] == EMPTY) {
            addPawnMove(pos, sq, sq + forward, EMPTY, allMoves);
            if (ranks[sq] == rank && pos->pieces[sq + 2 * forward] == EMPTY) {
                addQuietMove(pos, MOVE(sq, sq + 2 * forward, EMPTY, EMPTY, PAWN_START_FLAG), allMoves);
//                printf("%d\n", __LINE__);
            }
        }
        if (pieceSide[pos->pieces[sq + left]] == (side ^ 1)) {
            addPawnMove(pos, sq, sq + left, pos->pieces[sq + left], allMoves);
//            printf("%d\n", __LINE__);
        } else if (sq + left == pos->enPas) {
            addEnPassantMove(pos, MOVE(sq, sq + left, EMPTY, EMPTY, EN_PASSANT_FLAG), allMoves);
//            printf("%d\n", __LINE__);
        }

        if (pieceSide[pos->pieces[sq + right]] == (side ^ 1)) {
            addPawnMove(pos, sq, sq + right, pos->pieces[sq + right], allMoves);
        } else if (sq + right == pos->enPas) {
            addEnPassantMove(pos, MOVE(sq, sq + right, EMPTY, EMPTY, EN_PASSANT_FLAG), allMoves);
//            printf("%d\n", __LINE__);
        }
    }
}
