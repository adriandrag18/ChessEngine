// Created by adrian on 17.06.2020.

#ifndef INIT_H
#define INIT_H

#include "struct.h"

#define SQ64(sq120) (sq120ToSq64[(sq120)])
#define SQ120(sq64) (sq64ToSq120[(sq64)])
#define SET(bb, sq) ((bb) |= setMasks[(sq)])
#define CLEAR(bb, sq) ((bb) &= clearMasks[(sq)])

extern U64 setMasks[64];
extern U64 clearMasks[64];
extern U32 sq120ToSq64[120];
extern U32 sq64ToSq120[64];
extern U32 files[120];
extern U32 ranks[120];
extern U64 pieceKeys[13][120];
extern U64 sideKey;
extern U64 castleKeys[16];
extern void allInit();

#endif // INIT_H
