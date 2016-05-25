#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h> 

int testSmithy(){
	

	//initialize game 
	int options[] = {0};
	struct gameState state;
	int k[10] = {cutpurse, sea_hag, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};	
	initializeGame(4, k, 78, &state);


	int testVal = cardEffect(sea_hag, options[0],options[1],options[2], &state, NULL, NULL);
	assert(testVal == 0);

	printf("TEST 8 HAS PASSED. \n");
	return 0;

}

int main(){
	return testSmithy();
}