
#include "blocks.h"
#include "blockchain.h"

int main(){

    srand(time(NULL));
    int size;
    int difficulte;
    
    printf("Saisir un nombre de bloc pour la bc");
    scanf("%d",&size);
    printf("Saisir une difficulté");
    scanf("%d",&difficulte);
    printf("yo");
    Blockchain* b = CreerBlockChain(size, difficulte);

    
    return 0;
}
