#include "transactions.h"

const char CHARSET[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

const char* getCharsetAddress(){
	return CHARSET;
}

void gen_transactions(TransactionList* tx)
{

	char *userS;
	char *userD;
	int sUsername_length;
	int dUsername_length;

	tx->txList = malloc(sizeof(Transaction) * tx->length);

	for (int i = 0; i < tx->length; i++)
	{

		sUsername_length = rand() % 20 + 5;
		userS = malloc((sUsername_length + 1) * sizeof(char));

		for (int j = 0; j < sUsername_length; j++)
		{
			userS[j] = CHARSET[rand() % CHARSET_LEN];
		}
		userS[sUsername_length] = 0;

		dUsername_length = rand() % 20 + 5;
		userD = malloc((dUsername_length + 1) * sizeof(char));

		for (int k = 0; k < dUsername_length; k++)
		{
			userD[k] = CHARSET[rand() % CHARSET_LEN];
		}
		userD[dUsername_length] = 0;

		tx->txList[i].strLen = (sUsername_length + dUsername_length + 39 + 1 + 1);
		tx->txList[i].strTrans = malloc(tx->txList[i].strLen * sizeof(char));

		sprintf(tx->txList[i].strTrans, "Source: user %s - Destination: user %s\n", userS, userD);
		tx->txList[i].strTrans[tx->txList[i].strLen - 1] = 0;
		tx->txList[i].value = rand() % 100000;
		free(userS);
		free(userD);
	}

}

char** txListToStringList(TransactionList* tx){
	char** result = malloc(sizeof(char*) * tx->length);
	
	for(int i = 0; i < tx->length; i++){
        result[i] = malloc(sizeof(char) * tx->txList[i].strLen + 1);
        strcpy(result[i], tx->txList[i].strTrans);
    }
	return result;
}
