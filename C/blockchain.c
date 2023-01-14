#include "blocks.h"
#include "blockchain.h"


Blockchain* CreerBlockChain(int size, int difficulte){
    Blockchain* bc = malloc(sizeof(Blockchain));
    bc->size = size;
    bc->genesis = GenererGenesis();
    bc->block = (Block*)bc->genesis;
    MineBlock(bc->block, difficulte);
    printf("Block #%d\n", bc->block->numBlock);
    printf("Prev hash: %s\n", bc->block->prevHash);
    printf("Cur hash : %s\n", bc->block->currHash);
    printf("Nonce: %d\n", bc->block->nonce);
    printf("TimeStamp : %s\n", bc->block->timeStamp);

    for(int i = 0; i < bc->size; i++){

        bc->block->nextBlock = malloc(sizeof(Block));

        bc->block->nextBlock->prevBlock = bc->block;
        bc->block = bc->block->nextBlock;
        bc->block->numBlock = bc->block->prevBlock->numBlock+1;
        bc->block->prevHash = bc->block->prevBlock->currHash;
        bc->block->currHash = NULL;
        bc->block->nextBlock = NULL;
        bc->block->nonce = 0;
        bc->block->timeStamp = getTimeStamp();
        

        MineBlock(bc->block, difficulte);
        printf("Block #%d\n", bc->block->numBlock);
    	printf("Prev hash: %s\n", bc->block->prevHash);
    	printf("Cur hash : %s\n", bc->block->currHash);
    	printf("Nonce: %d\n", bc->block->nonce);
    	printf("TimeStamp : %s\n", bc->block->timeStamp);
    }
    return bc;
}


