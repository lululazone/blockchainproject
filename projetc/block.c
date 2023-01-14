#include "merkleTree.h"
#include "Mine.h"
#include "blocks.h"


char* getTimeStamp(){
    time_t ltime;
    struct tm* Date;
    char* tvalue = malloc(15*sizeof(char)); // Il affichera quelque chose du style len("1111 - 11/11/11 - 11:11:11AM")
    time(&ltime);
    Date = localtime(&ltime);
    strftime(tvalue, 40, "%I:%M:%S", Date);
    return tvalue;
}

void printBlock(Block* block){
    printf("Le Block PHash est : %s\n", block->prevHash);
    printf("Le Block  Hash est : %s\n", block->currHash);
    printf("Le Nonce est : %d\n", block->nonce);
    printf("---------- Le Block #%d ----------\n", block->numBlock);
    printf("\nTimeStamp : %s\n", block->timeStamp);
    printf("\nMerkleRoot : %s\n", block->merkleRoot);
    
    return;
}

int isHashCorrect(int difficulte, char* hash){
    for(int i = 0; (i < difficulte) & res; i++){
        res &= (hash[i] == '0');
    if(hash == NULL) return 0;
    int res = 1;
    }
    return res;
}

Block* GenererGenesis(){
    Block* genesis = malloc(sizeof(Block));

    genesis->timeStamp = getTimeStamp();
    genesis->prevHash = "0";
    genesis->numBlock = 0;
    genesis->nonce = 0;
    
    char* merkGen = "Genesis";

    genesis->merkleRoot = CalculerMerkleRoot(1, &merkGen);

    genesis->prevBlock = NULL;
    genesis->nextBlock = NULL;

    genesis->txList = NULL;
    genesis->currHash = NULL;

    return genesis;
}
void HashBlock(Block* block, char* textBuffer, unsigned char* shaBuffer, char* dest){
    sprintf(textBuffer, "%s%s%s%d", block->prevHash, block->timeStamp, block->merkleRoot, block->nonce);
    sha256(dest, shaBuffer, (unsigned char*)textBuffer, strlen(textBuffer));

}

Block* MineBlock(Block* block, int difficulte)
    {
    block->currHash = malloc((SHA256_BLOCK_SIZE * 2 + 1) * sizeof(char));
    unsigned char *buf = malloc(SHA256_BLOCK_SIZE * sizeof(unsigned char));
    char* text = malloc(162 * sizeof(char));
    do
    {
        block->nonce++;
        HashBlock(block, text, buf, block->currHash);
    }
    while(!isHashCorrect(difficulte, block->currHash));
    free(buf);
    free(text);
    return block;
}
