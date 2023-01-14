#include "merkleTree.h"

void sha256ToString(char* dest, unsigned char* data){
    for(int i = 0; i < SHA256_BLOCK_SIZE; i++){
        sprintf((dest + (i * 2)), "%02x", data[i] & 0xFF);
    }
    dest[SHA256_BLOCK_SIZE * 2] = 0;
}

char *sha256ToString1(unsigned char *hex)
{
    char *resultat = malloc((SHA256_BLOCK_SIZE * 2 + 1) * sizeof(char));
    sha256ToString(resultat, hex);
    return resultat;
}


void sha256(char* dest, unsigned char* shaBuffer, unsigned char* data, unsigned int dataLen){
    SHA256_CTX ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, data, dataLen);
    sha256_final(&ctx, shaBuffer);
    
    sha256ToString(dest, shaBuffer);
}

char *sha256W(unsigned char *data, unsigned int dataLen)
{
    unsigned char *buf = malloc(SHA256_BLOCK_SIZE * sizeof(unsigned char));
    char *resultat = malloc((SHA256_BLOCK_SIZE * 2 + 1) * sizeof(char));

    sha256(resultat, buf, data, dataLen);

    free(buf);

    return result;
}

char *mergeDataHash(unsigned char *dataA, unsigned char *dataB, int dataLenA, int dataLenB)
{
    char *b_1 = sha256W(dataA, dataLenA);
    char *b_2 = sha256W(dataB, dataLenB);
    char *result = malloc((SHA256_BLOCK_SIZE * 4 + 1) * sizeof(char)); 
    
    strcpy(resultat, b_1);
    strcpy(resultat + 2 * SHA256_BLOCK_SIZE, b_2);
    
    resultat[SHA256_BLOCK_SIZE * 4] = 0;

    free(b_1);
    free(b_2);

    return result;
}

merkleNode *CreerTree(int leafCount, char **list, int *ind)
{

    merkleNode *mNode = malloc(sizeof(merkleNode));

    if (leafCount <= 1)
    {
        mNode->nType = leaf;
        mNode->content = malloc(strlen(list[*ind]) + 1); // + 1 bc strings ends with \0
        strcpy((char *)mNode->content, list[*ind]);
        (*ind)++;
        return mNode;
    }

    mNode->right = CreerTree(leafCount / 2, list, ind);
    mNode->nType = node;

    if (leafCount % 2 == 0)
    {
        mNode->left = CreerTree(leafCount / 2, list, ind);
    }
    else
    {
        mNode->left = CreerTree(leafCount / 2 + 1, list, ind);
    }

    if (mNode->right->nType == leaf && mNode->left->nType == leaf)
    {
        mNode->nType = leaf;

        int lSize = strlen(mNode->left->content), rSize = strlen(mNode->right->content);

        mNode->content = mergeDataHash((unsigned char *)mNode->left->content, (unsigned char *)mNode->right->content, lSize, rSize);

        free(mNode->left->content);
        free(mNode->right->content);

        free(mNode->left);
        free(mNode->right);

        mNode->left = NULL;
        mNode->right = NULL;
    }

    return mNode;
}

merkleNode *CreerTreeW(int leafCount, char **list)
{
    int ind = 0;
    if(leafCount < 2){
        printf("Not enough items in list to create a tree !\n");
        return NULL;
    }
    return createTree(leafCount, list, &ind);
}

char *CalculerMerkleRoot(int leafCount, char **list)
{
    char* resultat;
    if(leafCount == 1){
        resultat = sha256W((unsigned char *)list[0], strlen(list[0]));
    }else{
        merkleNode *tree = createTreeW(leafCount, list);
        resultat = sha256W((unsigned char *)tree->content, 2 * sizeof(tree->content));

        free(tree->content);
        free(tree);
    }
    return resultat;
}

