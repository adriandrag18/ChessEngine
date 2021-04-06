//
// Created by adrian on 17.06.2020.
//

#ifndef GENERATOR_H
#define GENERATOR_H

extern int isSqAttacked(U32 sq, U32 attackingSide, const Board *pos);
extern void generateAllMoves(const Board *pos, Vector *allMoves);
extern void generateCapturesAllMoves(const Board *pos, Vector *allMoves);

#endif // GENERATOR_H
