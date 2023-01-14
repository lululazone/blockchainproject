
#include "blocks.h"
#include "sha256.h"




int isHashCorrect(int difficulte, char* hash){
    if(hash == NULL) return 0;
    int res = 1;
    for(int i = 0; (i < difficulte) & res; i++){
        if(hash[i] != '0'){
          res = 0;
        }
    
    }
    return res;
}

Block* GenererGenesis(){
    Block* genesis = malloc(sizeof(Block));
    genesis->prevBlock = NULL;
    genesis->nextBlock = NULL;
    genesis->currHash = NULL;
    genesis->timeStamp = getTimeStamp();
    genesis->prevHash = "0";
    genesis->numBlock = 0;
    genesis->nonce = 0;
    char* merkGen = "Genesis";
    

    return genesis;
}

char* getTimeStamp(){
    time_t ltime;
    struct tm* Date;
    char* tvalue = malloc(15*sizeof(char)); 
    time(&ltime);
    Date = localtime(&ltime);
    strftime(tvalue, 40, "%I:%M:%S", Date);
    return tvalue;
}


void HashBlock(Block* block, char* textBuffer, unsigned char* shaBuffer, char* dest){
    sprintf(textBuffer, "%s%s%d", block->prevHash, block->timeStamp, block->nonce);
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


void sha256ToString(char* dest, unsigned char* data){
    for(int i = 0; i < SHA256_BLOCK_SIZE; i++){
        sprintf((dest + (i * 2)), "%02x", data[i] & 0xFF);
    }
    dest[SHA256_BLOCK_SIZE * 2] = 0;
}

char *sha256ToStringW(unsigned char *hex)
{
    char *result = malloc((SHA256_BLOCK_SIZE * 2 + 1) * sizeof(char));
    sha256ToString(result, hex);
    return result;
}


void sha256(char* dest, unsigned char* shaBuffer, unsigned char* data, unsigned int LongDonnee){
    SHA256_CTX ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, data, LongDonnee);
    sha256_final(&ctx, shaBuffer);

    sha256ToString(dest, shaBuffer);
}

char *sha256W(unsigned char *data, unsigned int LongDonnee)
{
    unsigned char *buf = malloc(SHA256_BLOCK_SIZE * sizeof(unsigned char));
    char *result = malloc((SHA256_BLOCK_SIZE * 2 + 1) * sizeof(char));

    sha256(result, buf, data, LongDonnee);

    free(buf);

    return result;
}
