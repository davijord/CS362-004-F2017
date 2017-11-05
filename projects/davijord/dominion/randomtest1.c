/*
 * randomtestcard1.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard1: randomtestcard1.c dominion.o rngs.o
 * 	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TESTCARD "smithy"

int test = 0;

int assert(int i, int j){
	if(i == j){
		return 1;
	}else{return 0;}
}

int main(){
	srand(time(NULL));

	int TESTS = 1000;

	for (int i = 0; i < TESTS; i++){
		int handpos = rand() % MAX_HAND;
		int choice1 = rand() % 27;
		int choice2 = rand() % 27;
		int choice3 = rand() % 27;
		int bonus = rand() % 27;
		int seed = floor(rand() % 5000 + 1000);
		int numPlayers = (rand() % 2) + 2;
		int thisPlayer = rand() % numPlayers;
		struct gameState G, testG;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};

		//initialize game
		initializeGame(numPlayers,k, seed, &G);
		
		G.whoseTurn = thisPlayer;
		G.deckCount[thisPlayer] = (rand() % 5) + 5;
		G. discardCount[thisPlayer] = (rand() % 5) + 5;
		G.handCount[thisPlayer] = (rand() % 5) + 5;
		
		G.hand[thisPlayer][handpos] = smithy;

		memcpy(&testG, &G, sizeof(struct gameState));
		
		cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
		
		if(assert(testG.handCount[thisPlayer], G.handCount[thisPlayer] + 3)){
			test++;
		}
	}

	printf("Test passed %d times\n", test);	

	return 0;
}

