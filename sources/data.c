// Created by adrian on 17.06.2020.

#include "../headers/struct.h"

const char pcsChar[] = ".PNBRQKpnbrqk";
const char sideChar[] = "wb-";
const int pieceVal[13] = {0, 100, 325, 325, 550, 1000, 50000, 100, 325, 325, 550, 1000, 50000};
const int isPieceBig[13] = {false, false, true, true, true, true, true, false, true, true, true, true, true};
const int isPieceMaj[13] = {false, false, false, false, true, true, true, false, false, false, true, true, true};
const int isPieceMin[13] = {false, false, true, true, false, false, false, false, true, true, false, false, false};
const int isKn[13] = {false, false, true, false, false, false, false, false, true, false, false, false, false};
const int isKi[13] = {false, false, false, false, false, false, true, false, false, false, false, false, true};
const int isRQ[13] = {false, false, false, false, true, true, false, false, false, false, true, true, false};
const int isBQ[13] = {false, false, false, true, false, true, false, false, false, true, false, true, false};
const int isPawn[13] = {false, true, false, false, false, false, false, true, false, false, false, false, false};
const int pieceSide[13] = {BOTH, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK};
const int castlePerm[120] = {15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 13, 15, 15, 15, 12, 15, 15, 14, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15,  7, 15, 15, 15,  3, 15, 15, 11, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
                             15, 15, 15, 15, 15, 15, 15, 15, 15, 15
                             };
int mirror64[64] = {56, 57, 58, 59, 60, 61, 62, 63,
                    48, 49, 50, 51, 52, 53, 54, 55,
                    40, 41, 42, 43, 44, 45, 46, 47,
                    32, 33, 34, 35, 36, 37, 38, 39,
                    24, 25, 26, 27, 28, 29, 30, 31,
                    16, 17, 18, 19, 20, 21, 22, 23,
                     8,  9, 10, 11, 12, 13, 14, 15,
                     0,  1,  2,  3,  4,  5,  6,  7
                    };
char *fenArray[16] = {
        "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1",             // 0
        "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1",          // 1
        "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2",        // 2
        "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2",       // 3
        "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1", // 4
        "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1",  // 5
        "rnbqkbnr/p1p1p3/3p3p/1p1p4/2P1Pp2/8/PP1P1PpP/RNBQKB1R b KQkq e3 0 1",  // 6
        "5k2/1n6/4n3/6N1/8/3N4/8/5K2 w - - 0 1",                                // 7
        "6k1/8/5r2/8/1nR5/5N2/8/6K1 w - - 0 1",                                 // 8
        "6k1/8/4nq2/8/1nQ5/5N2/1N6/6K1 w - - 0 1",                              // 9
        "6k1/1b6/4n3/8/1n4B1/1B3N2/1N6/2b3K1 w - - 0 1",                        // 10
        "r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1",                                 // 11
        "3rk2r/8/8/8/8/8/6p1/R3K2R w KQk - 0 1",                                // 12
        "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1", // 13
        "2rr3k/pp3pp1/1nnqbN1p/3pN3/2pP4/2P3Q1/PPB4P/R4RK1 w - - 0 1",          // 14
        "r1b1k2r/ppppnppp/2n2q2/2b5/3NP3/2P1B3/PP3PPP/RN1QKB1R w KQkq - 0 1",   // 15
};

