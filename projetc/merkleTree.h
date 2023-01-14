#ifndef MERKLE_HEADER
    #define MERKLE_HEADER

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "sha256.h"

    enum nodeType
    {
        node,
        leaf
    };

    typedef enum nodeType nodeType;

    typedef struct merkleNode
    {
        nodeType nType;
        char *content;
        struct merkleNode *left;
        struct merkleNode *right;
    } merkleNode;

    void sha256ToString(char* dest, unsigned char* data);
    char *sha256ToStringW(unsigned char *hex);
    void sha256(char* dest, unsigned char* shaBuffer, unsigned char* data, unsigned int dataLen);
    char *sha256W(unsigned char *data, unsigned int dataLen);
    char *mergeDataHash(unsigned char *dataA, unsigned char *dataB, int dataLenA, int dataLenB);
    merkleNode *createTree(int leafCount, char **list, int *ind);
    merkleNode *createTreeW(int leafCount, char **list);
    char *calcMerkleRoot(int leafCount, char **list);
#endif