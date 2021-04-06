// Created by adrian on 17.06.2020.

#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdio.h>

typedef unsigned long long U64;
typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;

enum {
    EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK
};
enum {
    A, B, C, D, E, F, G, H, NONE
};
enum {
    RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE
};
enum {
    WHITE, BLACK, BOTH
};
enum {
    false, true
};
enum {
    WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8
};
enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ, OFFBOARD
};

//  100  100  100  100  100  100  100  100  100  100
//  100  100  100  100  100  100  100  100  100  100
//  100   56   57   58   59   60   61   62   63  100
//  100   48   49   50   51   52   53   54   55  100
//  100   40   41   42   43   44   45   46   47  100
//  100   32   33   34   35   36   37   38   39  100
//  100   24   25   26   27   28   29   30   31  100
//  100   16   17   18   19   20   21   22   23  100
//  100    8    9   10   11   12   13   14   15  100
//  100    0    1    2    3    4    5    6    7  100
//  100  100  100  100  100  100  100  100  100  100
//  100  100  100  100  100  100  100  100  100  100

//  91   92   93   94   95   96   97   98
//  81   82   83   84   85   86   87   88
//  71   72   73   74   75   76   77   78
//  61   62   63   64   65   66   67   68
//  51   52   53   54   55   56   57   58
//  41   42   43   44   45   46   47   48
//  31   32   33   34   35   36   37   38
//  21   22   23   24   25   26   27   28

#define DEBUG

// 0000 0000 0000 0000 0000 0111 1111 -> From 0x7F
// 0000 0000 0000 0011 1111 1000 0000 -> To >> 7, 0x7F
// 0000 0000 0011 1100 0000 0000 0000 -> Captured >> 14, 0xF
// 0000 0000 0100 0000 0000 0000 0000 -> EnPars 0x40000
// 0000 0000 1000 0000 0000 0000 0000 -> Pawn Start 0x80000
// 0000 1111 0000 0000 0000 0000 0000 -> Promoted Piece >> 20, 0xF
// 0001 0000 0000 0000 0000 0000 0000 -> Castle 0x1000000

#define FROM(m) (m & (U32)0x7F)
#define TO(m) ((m >> (U32)0x7) & (U32)0x7F)
#define CAPTURED(m) ((m >> (U32)0xE) & (U32)0xF)
#define PROMOTED(m) ((m >> (U32)0x14) & (U32)0xF)
#define EN_PASSANT_FLAG ((U32) 0x40000)  // EnPass
#define PAWN_START_FLAG ((U32) 0x80000)  // Pawn Start
#define CASTLE_FLAG ((U32) 0x1000000)    // Castling

#define MOVE(f,t,ca,pro,fl) ( (f) | ((t) << 7) | ( (ca) << 14 ) | ( (pro) << 20 ) | (fl))
#define FR2SQ(f, r) ( (21 + (f)) + ((r) * 10) ) // file-rank to square in 120 array
#define MATE 29000

#ifndef DEBUG
#define ASSERT(n)
#define TABLE_SIZE 0x3000000
#else
#define TABLE_SIZE 0x180000
#define ASSERT(n)                       \
if(!(n)) {                              \
    printf("%s - Failed", #n);          \
    printf("At %s.",__TIME__);          \
    printf("In %s ",__FILE__);          \
    printf("at line %d\n",__LINE__);    \
    exit(1);                            \
}
#endif

#ifndef DEBUG
#define ASSERT2(n, move, b)
#else
#define ASSERT2(n, move, b)             \
if(!(n)) {                              \
    printf("%s, - Failed\n", #n);       \
    printMove(move);                    \
    printBoard(b);                      \
    printf("\nAt %s.",__TIME__);        \
    printf("In %s ",__FILE__);          \
    printf("at line %d\n",__LINE__);    \
    exit(1);                            \
}
#endif

typedef struct {
    U32 move;
    U32 score;
} Element;

typedef struct {
    Element moves[256];
    U32 size;
} Vector;

typedef struct {
    U32 move;
    U32 castlePerm;
    U32 enPas;
    U32 fiftyMoves;
    U64 hashKey;
} Undo;

typedef struct {
    U32 pieces[120];
    U64 pawns[3];

    U32 bigPieces[2];
    U32 majPieces[2];
    U32 minPieces[2];
    U32 material[2];

    U32 pcsNum[13];
    U32 pcsList[13][9];

    U32 side;
    U32 enPas;
    U32 fiftyMoves;
    U8 castlePerm;

    U32 ply;
    U32 searchPly;

    U64 hashKey;
    Undo history[1024];
} Board;

#define START_FEN  "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"
#define FEN1 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN2 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN3 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"
#define FEN4 "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"
#define PAWNMOVESW "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1"
#define PAWNMOVESB "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1"
#define KNIGHTSKINGS "5k2/1n6/4n3/6N1/8/3N4/8/5K2 w - - 0 1"
#define ROOKS "6k1/8/5r2/8/1nR5/5N2/8/6K1 w - - 0 1"
#define QUEENS "6k1/8/4nq2/8/1nQ5/5N2/1N6/6K1 w - - 0 1"
#define BISHOPS "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 w - - 0 1"
#define CASTLE1 "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1"
#define CASTLE2 "3rk2r/8/8/8/8/8/6b1/R3K2R w KQk - 0 1"
#define PERFTFEN "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1"
#define MATE3 "2rr3k/pp3pp1/1nnqbN1p/3pN3/2pP4/2P3Q1/PPB4P/R4RK1 w - - 0 1"
#define T1 "r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1"

#endif // STRUCT_H
