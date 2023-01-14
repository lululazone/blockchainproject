#include "Mine.h"
#include "transactions.h"

Miner* initMiner(){
    Miner* miner = malloc(sizeof(Miner));
    int idLength = rand() % 20 + 5;
    miner->id = malloc(idLength + 1);
    for(int i = 0; i < idLength; i++){
        miner->id[i] = getCharsetAddress()[rand() % CHARSET_LEN];
    }
    miner->id[idLength] = 0;
    return miner;
}

void sign(FILE* f, Miner* m){
    int idLength = strlen(m->id);
    char* signature = malloc(idLength + 12 + 1);
    sprintf(signature, "\nMined by : %s", m->id);
    fputs(signature, f);
    free(signature);
}

void freeMiner(Miner* miner){
    free(miner->id);
    free(miner);
}
