#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h" 


int testFullDeckCount(){
	

	//initialize game 
	struct gameState state;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
	initializeGame(4, k, 78, &state);
	int expectedVal = 7;
	int testVal = 7;

	int testVal = fullDeckCount(0,1, &state);

	assert(expectedVal == testVal);

	printf("TEST 2 HAS PASSED. \n");
	return 0;

}

int main(){
	return testFullDeckCount();
}