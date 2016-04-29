#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h> 

int testGardens(){
	

	//initialize game 
	int options[] = {0};
	struct gameState state;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
	initializeGame(4, k, 78, &state);

	int testVal = cardEffect(gardens, options[0],options[1],options[2], &state, NULL, NULL);
	if(testVal == 0){
		printf("TEST 7 HAS PASSED. \n");
	}else{
		printf("TEST 7 HAS failed. \n");
	}
	return 0;

}

int main(){
	return testGardens();
}