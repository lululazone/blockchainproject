#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "transactions.h"
#include "Mine.h"


struct Blockchain {
        int size;
        const struct Block* genesis;
        struct Block* block;
    };
    
typedef struct Blockchain Blockchain;

Blockchain* CreerBlockChain(int size, int difficulte, int txPerBlocks, Miner* miner);
