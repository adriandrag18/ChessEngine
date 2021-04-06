// Created by adrian on 17.06.2020.
#include "../headers/struct.h"
#include <stdlib.h>

#define RAND64 ((U64)rand() | (U64)rand() << 15 | (U64)rand() << 30 |\
                 (U64)rand() << 45 | ((U64)rand() & 0xf) << 60)

#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma ide diagnostic ignored "cert-msc50-cpp"

U32 sq120ToSq64[120];
U32 sq64ToSq120[64];
U32 files[120];
U32 ranks[120];
U64 pieceKeys[13][120];
U64 sideKey;
U64 castleKeys[16];
U64 setMasks[64];
U64 clearMasks[64];

void initBitMasks() {
    for (U8 i = 0; i < 64; ++i) {
        setMasks[i] = 0ULL | (1ULL << i);
        clearMasks[i] = ~setMasks[i];
    }
}

void initHashKeys() {
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 120; ++j)
            pieceKeys[i][j] = RAND64;
    }
    sideKey = RAND64;
    for (int k = 0; k < 16; ++k)
        castleKeys[k] = RAND64;
}

void initFilesRanks() {
    for (int i = 0; i < 120; ++i) {
        files[i] = OFFBOARD;
        ranks[i] = OFFBOARD;
    }
    for (int rank = RANK_1; rank <= RANK_8; ++rank) {
        for (int file = A; file <= H; ++file) {
            files[FR2SQ(file, rank)] = file;
            ranks[FR2SQ(file, rank)] = rank;
        }
    }
}

void initSq120To64() {
    for (int i = 0; i < 120; ++i)
        sq120ToSq64[i] = OFFBOARD;

    for (int rank = RANK_1; rank <= RANK_8; ++rank) {
        for (int file = A; file <= H; ++file) {
            sq120ToSq64[FR2SQ(file, rank)] = rank * 8 + file;
            sq64ToSq120[rank * 8 + file] = FR2SQ(file, rank);
        }
    }
}

void initOpeningBook() {

}

void allInit() {
    initBitMasks();
    initHashKeys();
    initFilesRanks();
    initSq120To64();
    initOpeningBook();
}

#pragma clang diagnostic pop