#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Blockchain {
        int size;
        const struct Block* genesis;
        struct Block* block;
    };
    
typedef struct Blockchain Blockchain;

Blockchain* CreerBlockChain(int size, int difficulte);
