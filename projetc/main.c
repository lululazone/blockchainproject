#include "transactions.h"
#include "blocks.h"
#include "Mine.h"
#include "merkleTree.h"
#include "blockchain.h"

int main(){

    srand(time(NULL));
    int size;
    int difficulte;
    int txmax;
    

    Miner* mine = initMiner();
    printf("Saisir un nombre de bloc pour la bc");
    scanf("%d",&size);
    printf("Saisir une difficulté");
    scanf("%d",&difficulte);
    printf("Saisir un nombre max de transactions");
    scanf("%d",&txmax);
    
    Blockchain* b = CreerBlockChain(size, difficulte, txmax, mine);

    
    return 0;
}
