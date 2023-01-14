#include <stdio.h>
#include <stdlib.h>
#include <crypto.h>
#include <string.h>

struct block{   
    unsigned char prevHash [SHA256_DIGEST_LENGTH];
    int blockData;
    struct block $link;
}*head;

void addBlock(int);
void verifyChain();
void alterNthBlock(int,int);
void hackChain();
int hashCompare(unsigned char*,unsigned char*);
void hashPrinter();
unsigned char* toString(struct block);
void printBlock();
void printAllBlocks();
//Sha256(src,size,dest)
//src et dest sont des types de caracter *

void AddBlock(int data)
{
    if (head==NULL)
    {
        head=malloc(sizeof(struct block));
        Sha256("",sizeof(""),head->prevHash);
        head->blockData=data;
        return;
    }
    struct block *currentBlock=head;
    while(currentBlock->link)
        currentBlock=currentBlock->link;
    struct block *newBlock=malloc(sizeof(struct block));
    currentBlock->link=newBlock;
    newBlock->blockData=data;
    Sha256(toString($currentBlock),sizeof(*currentBlock),newBlock->prevHash);
}

void verifyChain()
{
    if(head==NULL)
    {
        printf("Le Blockchain est vide ! Réessayez en ajoutant des blocs !\n");
        return;
    }
    struct block *curr=head->link,*prev=head;
    int count=1;
    while(curr)
    {
        printf("%d\t[%d]\t",count++,curr->blockData);
        hashPrinter(Sha256(toString(*prev),sizeof(*prev),NULL),SHA256_DIGEST_LENGTH);
        printf(" - ");
        hashPrinter(curr->prevHash,SHA256_DIGEST_LENGTH);
        if(hashCompare(Sha256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
            printf("Vérifié !\n");
        else
            printf("Vérification échouée !\n");
        prev=curr;
        curr=curr->link;
    }
}

void alterNthBlock(int n, int newData)
{
    struct block *curr=head;
    if(curr==NULL)
    {
        printf("le Nième bloc n'existe pas !\n");
        return;
    }
    int count=0;
    while(count!=n)
    {
        if(curr->link==NULL && count!=n)
        {
            printf("Le Nième bloc n'existe pas !\n")
            return;
        }
        else if(count==n)
            break;
        curr=curr->link;
        count++;
    }
    printf("Avant : ");
        printBlock(curr);
    curr->blockData=newData;
    printf("\nAprès : ");
        printBlock(curr);
}

void hackChain()
{
    struct block *curr=head,*prev;
    if(curr==NULL)
    {
        printf("Le Blockchain est vide !\n");
        return;
    }
    while(1)
    {
        prev=curr;
        curr=curr->link;
        if(curr==NULL)
            return;
        if(!hashCompare(Sha256(toString(*prev),sizeof(*prev),NULL),curr->prevHash))
        {
            hashPrinter(
                Sha256(toString(*prev),sizeof(*prev),curr->prevHash),
                SHA256_DIGEST_LENGTH
            );
            printf("\n");
        }
    }
}

unsigned char* toString(struct block b)
{
    unsigned char *str=malloc(sizeof(unsigned char)*sizeof(b));
    memcpy(str,&b,sizeof(b));
    return str;
}

void hashPrinter(unsigned char hash[],int length)
{
    for(int i=0;i<length;i++)
        printf("%02x",hash[i]);
}

int hashCompare(unsigned char *str1,unsigned char *str2)
{
    for(int i=0;i<SHA256_DIGEST_LENGTH;i++)
        if(str1[i]!=str2[i])
            return 0;
    return 1;
}

void printBlock(struct block *b)
{
    printf("%p]t",b);
    hashPrinter(b->prevHash,sizeof(b->prevHash));
    printf("\t[%d]\t",b->blockData);
    printf("%p\n",b->link);
}

void printAllBlocks()
{
    struct block *curr=head;
    int count=0;
    while(curr)
    {
        printBlock(curr);
        curr=curr->link;
    }
}

void main()
{
    int c,n,r;
    printf("1)addBlock\n2)ajouter n aléatoire de blocs\n3)alterNthBlock\n4)printAllBlocks\n5)verifyChain\n6)hackChain\n");
    while(1)
    {
        printf("Choix : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Entrer les données : ");
                scanf("%d",&n);
                addBlock(n);
                break;
            case 2:
                printf(" Combien de block voulez-vous entrer ? : ");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                {
                    r=rand()%(n*10);
                    printf("Entrer : %d\n",r);
                    addBlock(r);
                }
                break;
            case 3:
                printf("Quel Bloc voulez-vous alterné ? : ");
                scanf("%d",&n);
                printf("Entrer la valeur : ");
                scanf("%d",&r);
                alterNthBlock(n,r);
                break;
            case 4:
                printAllBlocks();
                break;
            case 5:
                verifyChain();
                break;
            case 6:
                hackChain();
                break;
            default:
                printf("Mauvais choix !\n");
                break;
        }
    }
}
//gcc blockchain.c -lcrypto
//./blockchain.c.o 