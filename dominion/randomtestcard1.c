#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

int testSmithy(int seed, int players){
	

	//Init game
	srand(seed);
	int numbGames = rand()%400+1;
	printf("numbgames: =%d", numbGames);
	int i;
	for(i=0; i<numbGames; i++){
		struct gameState state;
		int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
		int player = state.whoseTurn;
		initializeGame(players, k, seed, &state);
		int expectedVal = smithyEffect(player, -1, &state);
		int numCardsInHand = state.handCount[player];
		if(expectedVal==0){
			if(numCardsInHand <= state.handCount[player]){
				printf("smithyworked %d \n", i);
			}else{
				printf("Not enough cards picked up");
			}
		}else{
			printf("game not working");
		}

	}


	return 0;

}

int main( int argc, char *argv[]){
	int players = rand()%4+1;
	int seed = argc;
	return testSmithy(seed, players);
}