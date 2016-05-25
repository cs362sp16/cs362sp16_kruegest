#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h> 

int testGetWinners(){
	

	//initialize game 
	struct gameState state;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
	initializeGame(4, k, 78, &state);

	int players[] = {4};

	int testVal = getWinners(players, &state);

	assert(testVal == 0);

	printf("TEST 4 HAS PASSED. \n");
	return 0;

}

int main(){
	return testGetWinners();
}