/*
 * randometestadventurer.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 * 	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TESTCARD "adventurer"
int test;

int assert(int i, int j){
	if(i==j){
		return 1;
	}
	return 0;
}

int main(){
	srand(time(NULL));

	int TESTS = 1000;
	int i = 0;

	for (i = 0; i < TESTS; i++){
	int handPos = rand() % MAX_HAND;
	int seed = floor(rand() % 5000 + 1000);
	int numPlayers = (rand() % 2) + 2;
	int thisPlayer = rand() % numPlayers;
	int choice1 = rand() % 27, choice2 = rand() % 27, choice3 = rand() % 27, bonus = rand() % 27;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};
	//initialize game
	initializeGame(numPlayers,k, seed, &G);
	
	G.whoseTurn = thisPlayer;
	G.deckCount[thisPlayer] = (rand() % 5) + 5;
	G.discardCount[thisPlayer] = (rand() % 5) + 5;
	G.handCount[thisPlayer] = (rand() % 5) + 5;

	G.hand[thisPlayer][handPos] = adventurer;	

	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);	
	//deckCount, discardCount, handCount
	
	if(assert(testG.handCount[thisPlayer],G.handCount[thisPlayer] + 1) &&
	 	assert(testG.discardCount[thisPlayer],G.discardCount[thisPlayer] + 1) && 
		assert(testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 2)){test++;}

	}

	printf("Adventurer Test Passed %d times\n", test);	

	return 0;
}

