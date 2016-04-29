#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include "assert.h" 

int testSupplyCount(){
	

	//initialize game 
	struct gameState state;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
	initializeGame(4, k, 78, &state);

	int expectedVal = supplyCount(province, &state);

	assert(expectedVal == 12);

	printf("TEST 1 HAS PASSED. \n");
	return 0;

}

int main(){
	return testSupplyCount();
}