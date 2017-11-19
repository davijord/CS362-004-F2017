/*
 * testSmithy.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * testSmithy: testSmithy.c dominion.o rngs.o
 * 	gcc -o testSmithy -g testSmithy.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main(){
	int handPos = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};
	//initialize game
	initializeGame(numPlayers,k, seed, &G);
	
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);

	printf("Cards = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 3);
	return 0;
}

