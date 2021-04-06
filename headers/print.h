// Created by adrian on 17.06.2020

#ifndef PRINT_H
#define PRINT_H

#include "init.h"

extern void print120();
extern void print64();
extern void printFiles();
extern void printRanks();
extern char *prMove(U32 move);
extern char *prSq(U32 sq);
extern void printMove(U32 move);
extern void printBoard(const Board *pos);
extern void printBitBoard(U64 bb);
extern void showSqAttackedBySide(const int side, const Board *pos);

#endif // PRINT_H
