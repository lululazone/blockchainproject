#ifndef BLOCKS_HEADERS
#define BLOCKS_HEADERS

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "transactions.h"
    #include "Mine.h"

    struct Block {
        int nonce;
        int numBlock;

        struct Block* prevBlock;
        struct Block* nextBlock;
        
        TransactionList* txList;

        char* prevHash;
        char* currHash;
        char* timeStamp;
        char* merkleRoot;
    };

    typedef struct Block Block;


    

    Block* generateGenesis();
    void hashBlock(Block* block, char* textBuffer, unsigned char* shaBuffer, char* dest);
    char* getTimeStamp();
    int isHashCorrect(int difficulty, char* hash);
    Block* mineBlock(Block* block, int difficulty);
    void printBlock(Block* block);
    

#endif
