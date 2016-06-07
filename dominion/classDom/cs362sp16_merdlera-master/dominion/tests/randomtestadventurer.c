/*************************************************
* Random Card Test 1
* Card: adventurer
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assert.h"
#include "../dominion.h"

#define NUM_TESTS 10000

int main(int argc, char *argv[]){

	// No command line args provided
	if (argc != 2) {
		printf("Usage: %s <random_seed>\n", argv[0]);
		return 1;
	}
	else {
		struct gameState state;
		time_t seed = NULL;
		seed = strtol(argv[1], NULL, 10);
		srand(time(&seed));
		printf("Random Testing: adventurer");

	    // Set up game
	    int numPlayers = 2;
	    int supplyPos = 1;
	    int cards[10] = {
	        smithy,
	        adventurer,
	        gardens,
	        embargo,
	        cutpurse,
	        mine,
	        ambassador,
	        outpost,
	        baron,
	        tribute
	    };


		// Run tests
	    for (int i = 0; i < NUM_TESTS; i++) {
	        int players = 2 + rand() % (MAX_PLAYERS - 2);
	        int rand_num = rand();
	        int current_player = 0;
	        int result = NULL;

	        // Initialize new game
	        initializeGame(players, cards, rand_num, &state);

	        // Setup state attributes
	        state.deckCount[current_player] = rand() % MAX_DECK;
			// state.discardCount[current_player] = rand() %  MAX_DECK;
			state.discardCount[current_player] = 0;
	        state.handCount[current_player] = rand() %  MAX_HAND;

	        // Play card
	        result = cardEffect(adventurer, NULL, NULL, NULL, &state, 0, NULL);

	        // Check function return
	        myAssertTrue((result == 0), "cardEffect returns 0.");
	    }

    	checkAsserts();

    	return 0;
	}
}
