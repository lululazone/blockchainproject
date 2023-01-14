#ifndef TRANSACTIONS_HEADERS
    #define TRANSACTIONS_HEADERS 1

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    #define CHARSET_LEN 62
    
    struct Transact
    {
        int strLen;
        char *strTrans;
        long int value;
    };

    typedef struct Transact Transact;

    struct TransactList{
        Transact* txList;
        int length;
    };

    typedef struct TransactList TransactList;
    

    const char* getCharsetAddress();
    void gen_transactions(TransactList* tx);
    void TransactionsLibre(TransactList* tx);
    char** txListToStringList(TransactList* tx);
    

#endif