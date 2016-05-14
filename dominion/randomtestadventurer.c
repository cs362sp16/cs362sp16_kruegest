#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

int testADV(int seed, int players){
	

	//Init game
	srand(seed);
	int numbGames = rand()%400+1;
	printf("numbgames: =%d", numbGames);
	int options[] = {0};
	int i;
	for(i=0; i<numbGames; i++){
		struct gameState state;
		int k[10] = {cutpurse, embargo, smithy, village, gardens, 
				 adventurer, ambassador, steward, great_hall, minion};
		initializeGame(players, k, seed, &state);
		int player = state.whoseTurn;
		int numCardsInHand = state.handCount[player];
		int playerCoins = state.coins;
		int expectedVal = cardEffect(adventurer, options[0],options[1],options[2], &state, -1, NULL);
		if(expectedVal==0){
			if(numCardsInHand <= state.handCount[player] && playerCoins<=state.coins){
				printf("adventuererworked %d \n", i);
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
	return testADV(seed, players);
}