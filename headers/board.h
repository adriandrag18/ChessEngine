// Created by adrian on 17.06.2020.

#ifndef BOARD_H
#define BOARD_H

#include "struct.h"

extern int sqOnBoard(int sq);
extern int sideValid(int side);
extern int fileRankValid(int fr);
extern int pieceValidOrEmpty(int pce);
extern int pieceValid(int pce);
extern int popBit(U64 *bb);
extern int countBits(U64 bb);
extern int parseFEN(const char *fen, Board *pos);
extern char *getFEN(const Board *pos);
extern int checkBoard(const Board *pos);

#endif // BOARD_H
