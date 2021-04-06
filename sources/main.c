#include <stdio.h>
#include <stdlib.h>
#include "../headers/struct.h"
#include "../headers/data.h"
#include "../headers/init.h"
#include "../headers/print.h"
#include "../headers/board.h"
#include "../headers/test.h"
#include "../headers/generator.h"
#include "../headers/move.h"

int main() {
    allInit();
    Board pos[1];
    print64();
    print120();
    printFiles();
    printRanks();
    U64 bb = 0;
    printBitBoard(bb);
    bb |= (1ULL << (U32) SQ64(D2));
    printBitBoard(bb);
    testFEN();

//    Vector allMoves[1];
//    parseFEN(START_FEN, pos);
//    printBoard(pos);
//    generateAllMoves(pos, allMoves);
//
//    getchar();
//    for (int moveNum = 0; moveNum < allMoves->size; ++moveNum) {
//        int move = allMoves->moves[moveNum].move;
//
//        printf("\nMaking move... %s\n", prMove(move));
//        if (!makeMove(pos, move))
//            continue;
//        printBoard(pos);
//
//        printf("\nUndoing... %s\n", prMove(move));
//        undoMove(pos);
//        printBoard(pos);
//
//        getchar();
//    }

//3.Fen: 4k3/8/8/8/8/8/8/4K2R w K - 0 1, found 68 from 66
//4.Fen: 4k3/8/8/8/8/8/8/R3K3 w Q - 0 1, found 73 from 71
//7.Fen: 4k3/8/8/8/8/8/8/R3K2R w KQ - 0 1, found 116 from 112
//13.Fen: r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1, found 574 from 568
//14.Fen: r3k2r/8/8/8/8/8/8/1R2K2R w Kkq - 0 1, found 570 from 567
//15.Fen: r3k2r/8/8/8/8/8/8/2R1K2R w Kkq - 0 1, found 551 from 548
//16.Fen: r3k2r/8/8/8/8/8/8/R3K1R1 w Qkq - 0 1, found 550 from 547
//17.Fen: 1r2k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1, found 588 from 583
//18.Fen: 2r1k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1, found 563 from 560
//19.Fen: r3k1r1/8/8/8/8/8/8/R3K2R w KQq - 0 1, found 563 from 560
//22.Fen: 4k2r/8/8/8/8/8/8/4K3 b k - 0 1, found 68 from 66
//23.Fen: r3k3/8/8/8/8/8/8/4K3 b q - 0 1, found 73 from 71
//25.Fen: r3k2r/8/8/8/8/8/8/4K3 b kq - 0 1, found 116 from 112
//30.Fen: r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1, found 574 from 568
//31.Fen: r3k2r/8/8/8/8/8/8/1R2K2R b Kkq - 0 1, found 588 from 583
//32.Fen: r3k2r/8/8/8/8/8/8/2R1K2R b Kkq - 0 1, found 563 from 560
//33.Fen: r3k2r/8/8/8/8/8/8/R3K1R1 b Qkq - 0 1, found 563 from 560
//34.Fen: 1r2k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1, found 570 from 567
//35.Fen: 2r1k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1, found 551 from 548
//36.Fen: r3k1r1/8/8/8/8/8/8/R3K2R b KQq - 0 1, found 550 from 547

//    U64 nodes = 0;
//    parseFEN("4k3/8/8/8/8/8/8/4K2R w K - 0 1", pos);
//    showSqAttackedBySide(BLACK, pos);
//    printBoard(pos);
//    perf(pos, 2, &nodes);
//    printf("%llu\n", nodes);

    perfTest(2);

    return 0;
}
