#ifndef MINER_HEADER
    #define MINER_HEADER

    #include <stdio.h>

    struct Miner{
        char* id;
    };

    typedef struct Miner Miner;
    Miner* initMiner();
    void sign(FILE* f, Miner* m);
    void LibreMiner(Miner* miner);
    
#endif
