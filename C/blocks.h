#ifndef BLOCKS_HEADERS
#define BLOCKS_HEADERS

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    struct Block {
        int nonce;
        int numBlock;
        struct Block* prevBlock;
        struct Block* nextBlock;
        char* prevHash;
        char* currHash;
        char* timeStamp;
    };

    typedef struct Block Block;


    

    Block* GenererGenesis();
    void hashBlock(Block* block, char* textBuffer, unsigned char* shaBuffer, char* dest);
    char* getTimeStamp();
    int isHashCorrect(int difficulty, char* hash);
    Block* MineBlock(Block* block, int difficulty);
    

#endif
