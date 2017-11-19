/*
 * testRemodel.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * testRemodel: testRemodel.c dominion.o rngs.o
 * 	gcc -o testRemodel -g testRemodel.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "remodel"

int assert(int i, int j){
	if(i==j){
		return 1;
	}
	return 0;
}

int main(){
	int handPos = 0;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	int choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, remodel, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};
	//initialize game
	initializeGame(numPlayers,k, seed, &G);
	
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(remodel, choice1, choice2, choice3, &testG, handPos, &bonus);

	if(assert(testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1 - 1)){
		printf("Remodel test passed!\n");
	}

	return 0;
}
