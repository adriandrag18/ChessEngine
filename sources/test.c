// Created by adrian on 17.06.2020.
# include "../headers/data.h"
# include "../headers/struct.h"
# include "../headers/board.h"
# include "../headers/print.h"
# include "../headers/generator.h"
# include "../headers/move.h"
# include "string.h"

void testFEN() {
    Board *pos = (Board *) malloc(sizeof(Board));
    int k = 0, total = 16;

    for (int i = 0; i < 16; ++i) {
        char *fen = fenArray[i];
        if (parseFEN(fen, pos) < 0) {
            printf("\nError at parseFEN: %s\n", fen);
            printBoard(pos);
            continue;
        }
        char *fen2 = getFEN(pos);
        if (strcmp(fen, fen2) == 0)
            k++;
        else
            printf("%d.Failed\nOriginal FEN: %s\nGot      FEN: %s\n", i, fen, fen2);
    }

    char *line = (char *) malloc(200);
    char *fen;
    char del[2] = ";";
    size_t len = 200;
    FILE *fin = fopen("perftsuite.epd", "r");
    if (!fin) {
        printf("%p\n", fin);
        return;
    }
    while (getline(&line, &len, fin) > 0) {
        fen = strtok(line, del);
        fen[strlen(fen) - 1] = 0;
        total++;
        if (parseFEN(fen, pos) < 0) {
            printf("\n%d form perfsuite Error at parseFEN: %s\n", total - 16, fen);
            printBoard(pos);
            continue;
        }
        char *fen2 = getFEN(pos);
        if (strcmp(fen, fen2) == 0)
            k++;
        else
            printf("%d form perfsuite  Failed\nOriginal FEN: %s\nGot      FEN: %s\n",
                   total - 16, fen, fen2);

    }

    printf("\nTest parseFEN/getFEN completed: %d/%d\n\n", k, total);

    free(line);
    fclose(fin);
}

void perf(Board *pos, int depth, U64 *leafNodes) {
    ASSERT(checkBoard(pos))
    if (depth == 0) {
        (*leafNodes)++;
        return;
    }

    Vector allMoves[1];
    generateAllMoves(pos, allMoves);

//    printBoard(pos);
    for (int moveNum = 0; moveNum < allMoves->size; ++moveNum) {
        int move = allMoves->moves[moveNum].move;
        if (!makeMove(pos, move))
            continue;

//        printf("%s\n", prMove(move));
        perf(pos, depth - 1, leafNodes);
        undoMove(pos);
    }
}

void perfTest(int depth) {
    char *fen, *str, *line = (char *) malloc(200);
    char del[2] = ";";
    size_t len = 200;
    int total = 0, passed = 0;
    U64 totalNodes = 0;
    FILE *fin = fopen("perftsuite.epd", "r");

    if (!fin) {
        printf("%p\n", fin);
        return;
    }
    while (getline(&line, &len, fin) > 0) {
        fen = strtok(line, del);
        fen[strlen(fen) - 1] = 0;
        U64 results[6];
        for (int i = 0; i < 6; i++) {
            str = strtok(NULL, del);
            sscanf(str + 3, "%llu", &results[i]);
        }
        total += depth;
        Board pos[1];
        parseFEN(fen, pos);
        printf("%d.Fen: %s\n", total / depth, fen);
        for (int i = 1; i <= depth && i <= 6; i++){
            U64 leafNodes = 0;
            perf(pos, i, &leafNodes);
            if (leafNodes == results[i - 1]) {
                passed++;
            } else {
                printf("FAIL : found %llu from %llu\n",  leafNodes, results[i - 1]);
            }
            totalNodes += leafNodes;
            parseFEN(fen, pos);
        }
    }

    printf("\nPerf Test completed. Passed: %d/%d, visited: %llu nodes\n", passed, total, totalNodes);

    free(line);
    fclose(fin);
}
