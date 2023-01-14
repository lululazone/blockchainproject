#include "blocks.h"
#include "MerkleTree.h"
#include "Mine.h"
#include "blockchain.h"


Blockchain* CreerBlockChain(int size, int difficulté, int txPerBlocks, Miner* miner){
    Blockchain* bc = malloc(sizeof(Blockchain));
    bc->size = size;
    bc->genesis = GenerateGenesis();
    bc->block = (Block*)bc->genesis;

    MineBlock(bc->block, difficulté);
    printBlock(bc->block);

    for(int i = 0; i < bc->size; i++){
        char* fileName = malloc(50*sizeof(char));
        FILE* f;

        bc->block->nextBlock = malloc(sizeof(Block));

        bc->block->nextBlock->prevBlock = bc->block;
        bc->block = bc->block->nextBlock;
        bc->block->numBlock = bc->block->prevBlock->numBlock+1;
        bc->block->prevHash = bc->block->prevBlock->currHash;
        bc->block->currHash = NULL;
        bc->block->nextBlock = NULL;
        bc->block->nonce = 0;
        sprintf(fileName, "data/block_%d.dat", bc->block->numBlock);
        f = fopen(fileName, "w");


        bc->block->timeStamp = getTimeStamp();
        bc->block->txList = malloc(sizeof(TransactionList));
        bc->block->txList->length = txPerBlocks;
        gen_transactions(bc->block->txList);
        char** txListString = txListToStringList(bc->block->txList);
        bc->block->merkleRoot = CalculerMerkleRoot(txPerBlocks, txListString);

        for(int j = 0; j < txPerBlocks; j++){
            fputs(txListString[j], f);
            free(txListString[j]);
        }
        sign(f,miner);
        fclose(f);
        free(fileName);

        free(txListString);
        MineBlock(bc->block, difficulté);
        printBlock(bc->block);
    }
    return bc;
}


