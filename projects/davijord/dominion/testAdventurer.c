/*
 * testAdventurer.c
 *
 */

/*
 * Include the following lines in your makefile:
 *
 * testAdventurer: testAdventurer.c dominion.o rngs.o
 * 	gcc -o testAdventurer -g testAdventurer.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

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
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			 sea_hag, tribute, smithy, council_room};
	//initialize game
	initializeGame(numPlayers,k, seed, &G);
	
	memcpy(&testG, &G, sizeof(struct gameState));

	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);	
	//deckCount, discardCount, handCount
	
	if(assert(testG.handCount[thisPlayer],G.handCount[thisPlayer])){
		printf("Hand Count is the same!\n");
	}else{printf("Hand Count is different!\n");}

	if(assert(testG.discardCount[thisPlayer],G.discardCount[thisPlayer])){
		printf("Discard Count is the same!\n");
	}else{printf("Discard Count is different!\n");}

	if(assert(testG.deckCount[thisPlayer], G.deckCount[thisPlayer])){
		printf("Deck Count is the same!\n");
	}else{printf("Deck Count is different!\n");}

	return 0;
}

