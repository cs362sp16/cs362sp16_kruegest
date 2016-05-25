#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h> 

int testVillage(){
	

	//initialize game 
	struct gameState state;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
	initializeGame(4, k, 78, &state);

	int expectedVal = villageEffect(0, &state, NULL);

	assert(expectedVal == 0);

	printf("TEST 6 HAS PASSED. \n");
	return 0;

}

int main(){
	return testVillage();
}