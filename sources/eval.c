// Created by adrian on 17.06.2020.

#include "../headers/struct.h"
#include "../headers/board.h"
#include "../headers/init.h"

static const int pawnTable[64] = {
        0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,
        10	,	10	,	0	,	-10	,	-10	,	0	,	10	,	10	,
        5	,	0	,	0	,	5	,	5	,	0	,	0	,	5	,
        0	,	0	,	10	,	20	,	20	,	10	,	0	,	0	,
        5	,	5	,	5	,	10	,	10	,	5	,	5	,	5	,
        10	,	10	,	10	,	20	,	20	,	10	,	10	,	10	,
        20	,	20	,	20	,	30	,	30	,	20	,	20	,	20	,
        0	,	0	,	0	,	0	,	0	,	0	,	0	,	0
};

static const int knightTable[64] = {
        0	,	-10	,	0	,	0	,	0	,	0	,	-10	,	0	,
        0	,	0	,	0	,	5	,	5	,	0	,	0	,	0	,
        0	,	0	,	10	,	10	,	10	,	10	,	0	,	0	,
        0	,	0	,	10	,	20	,	20	,	10	,	5	,	0	,
        5	,	10	,	15	,	20	,	20	,	15	,	10	,	5	,
        5	,	10	,	10	,	20	,	20	,	10	,	10	,	5	,
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0	,
        0	,	0	,	0	,	0	,	0	,	0	,	0	,	0
};

static const int bishopTable[64] = {
        0	,	0	,	-10	,	0	,	0	,	-10	,	0	,	0	,
        0	,	0	,	0	,	10	,	10	,	0	,	0	,	0	,
        0	,	0	,	10	,	15	,	15	,	10	,	0	,	0	,
        0	,	10	,	15	,	20	,	20	,	15	,	10	,	0	,
        0	,	10	,	15	,	20	,	20	,	15	,	10	,	0	,
        0	,	0	,	10	,	15	,	15	,	10	,	0	,	0	,
        0	,	0	,	0	,	10	,	10	,	0	,	0	,	0	,
        0	,	0	,	0	,	0	,	0	,	0	,	0	,	0
};

static const int rookTable[64] = {
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0	,
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0	,
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0	,
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0	,
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0	,
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0	,
        25	,	25	,	25	,	25	,	25	,	25	,	25	,	25	,
        0	,	0	,	5	,	10	,	10	,	5	,	0	,	0
};

static const int mirror64[64] = {
        56	,	57	,	58	,	59	,	60	,	61	,	62	,	63	,
        48	,	49	,	50	,	51	,	52	,	53	,	54	,	55	,
        40	,	41	,	42	,	43	,	44	,	45	,	46	,	47	,
        32	,	33	,	34	,	35	,	36	,	37	,	38	,	39	,
        24	,	25	,	26	,	27	,	28	,	29	,	30	,	31	,
        16	,	17	,	18	,	19	,	20	,	21	,	22	,	23	,
        8	,	9	,	10	,	11	,	12	,	13	,	14	,	15	,
        0	,	1	,	2	,	3	,	4	,	5	,	6	,	7
};

U32 evalPosition(const Board *pos) {

    int pce;
    int pceNum;
    int sq;
    U32 score = pos->material[WHITE] - pos->material[BLACK];

    pce = wP;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score += pawnTable[SQ64(sq)];
    }

    pce = bP;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score -= pawnTable[mirror64[SQ64(sq)]];
    }

    pce = wN;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score += knightTable[SQ64(sq)];
    }

    pce = bN;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score -= knightTable[mirror64[SQ64(sq)]];
    }

    pce = wB;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score += bishopTable[SQ64(sq)];
    }

    pce = bB;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score -= bishopTable[mirror64[SQ64(sq)]];
    }

    pce = wR;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score += rookTable[SQ64(sq)];
    }

    pce = bR;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score -= rookTable[mirror64[SQ64(sq)]];
    }

    pce = wQ;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score += bishopTable[SQ64(sq)];
        score += rookTable[SQ64(sq)];
    }

    pce = bQ;
    for(pceNum = 0; pceNum < pos->pcsNum[pce]; ++pceNum) {
        sq = pos->pcsList[pce][pceNum];
        ASSERT(sqOnBoard(sq));
        score -= bishopTable[mirror64[SQ64(sq)]];
        score -= rookTable[mirror64[SQ64(sq)]];
    }

    if(pos->side == WHITE)
        return score;
    else
        return -score;
}
