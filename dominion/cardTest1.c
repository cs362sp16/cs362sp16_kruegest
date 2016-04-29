#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h> 

int testSmithy(){
	

	//initialize game 
	struct gameState state;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
	initializeGame(4, k, 78, &state);

	int expectedVal = smithyEffect(0, NULL, &state);

	assert(expectedVal == 0);

	printf("TEST 5 HAS PASSED. \n");
	return 0;

}

int main(){
	return testSmithy();
}