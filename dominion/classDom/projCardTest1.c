#include "dominion.h"
#include "rngs.h"
#include "myAssert.h"
#include "dominion_helpers.h"
#include "cardEffects.h"
#include <stdio.h>
#include <assert.h> 

int testSmithy(){
	

	//initialize game 
	struct gameState g;
	int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, council_room, steward, great_hall, minion};
	initializeGame(4, k, 78, &g);
	int r;

	gainCard(council_room, &g, 2, 0);
	r = playCard(5, 0, 0, 0, &g);
	myAssert(r == 0, "councilRoom failed", __LINE__);
	for(int i = 0; i < numHandCards(&g); ++i)
		myAssert(handCard(i, &g) != council_room, "Did not discard council room", __LINE__);
	for(int i = 0; i < 2; ++i)
	{
		r = buyCard(copper, &g);
		myAssert(r == 0, "Does not have 2 buy's. Should have got extra buy from council room", __LINE__);
	}
	myAssert(numHandCards(&g) == 9, "Player 0 does not have 9 cards", __LINE__);
	for(int i = 0; i < 3; ++i)
	{
		endTurn(&g);
		r = myAssert(numHandCards(&g) == 6, "Other players did not draw an extra card", __LINE__);
	}

	//done
	if(r == 0)
		printf("Tests completed successfully!\n");

	return 0;

}

int main(){
	return testSmithy();
}