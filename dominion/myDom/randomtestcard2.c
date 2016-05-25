#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

int testVillage(int seed, int players){
	

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
		int playerActions = state.numActions;
		initializeGame(players, k, seed, &state);
		int expectedVal = villageEffect(player, &state, -1);
		int numCardsInHand = state.handCount[player];
		if(expectedVal==0){
			if(numCardsInHand <= state.handCount[player] && state.numActions<=playerActions){
				printf("villagedrawaction worked %d \n", i);
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
				printf("game not working");

	int players = rand()%4+1;
	int seed = argc;
				printf("game not working");

	return testVillage(seed, players);
}