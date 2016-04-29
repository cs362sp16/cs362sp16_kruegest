#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h> 

int testInit(){
	

	//initialize game 
	struct gameState state;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
	int testInitVal = initializeGame(4, k, 78, &state);
	int expectedVal = 0;


	assert(expectedVal == testInitVal);

	printf("TEST 3 HAS PASSED. \n");
	return 0;

}

int main(){
	return testInit();
}