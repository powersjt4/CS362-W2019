/**
 * Jake Powers 
 * Random test for dominion function Great Hall()
 * TEST_DEBUG found in testHelpers.h 
 * 2.23.19
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "testHelpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h> // for rand(seed)



/*Shamelessly Lifted from http://www.dillonbhuff.com/?p=439*/
#define NUM_TEST 100 



int setupGame(int p, struct gameState *state){
    state->handCount[p] = (rand() % (MAX_HAND - 10)) + 10; // Making sure there are always at least 10 cards in deck and hand
    state->deckCount[p] = (rand() % (MAX_DECK - 10 )) + 10; 
        return 0;
}

int main(){
    srand(time(NULL));
    int kc[10]= {silver, gold, council_room, baron, minion, treasure_map, tribute, embargo, adventurer, cutpurse};
    struct gameState gs1;
    int randomSeed = 0;
    int rslt1 = 0;
	int handChoice1 = 0; 
	int coinChoice1 = 0;
    int choice1 = 1;
    printf("***  Starting Steward Random Tests  ***\n");

   for(int i = 0; i <= 100; i++){
	   
        if(i == 100 && choice1 < 3){ // Test other branch of steward card
			if(choice1 == 1){
				choice1 = 2; // Changes to coins choice
				handChoice1 = rslt1;// From first choice run
				rslt1 = 0; 
				i = 0;//Reset counter

			}
			else{
				coinChoice1 = rslt1;
				choice1 = 3; // Changes to discard choice will not hit this if statement after final run
				rslt1 = 0; //Reset counter
				i = 1;//Reset counter
			}
			
        } 
        randomSeed = 1 + (rand() % 100);
        initializeGame(rand() % (MAX_PLAYERS - 1)+2, kc, randomSeed, &gs1);
        gs1.whoseTurn = rand() % (gs1.numPlayers); // Set random player
        int player = gs1.whoseTurn;
        setupGame(player, &gs1); // Set the players stats to random values
        if(TEST_DEBUG) printGameState(player,&gs1);

        int pHand = gs1.handCount[player];
		int pCoins = gs1.coins;
        cardEffect(steward, choice1 ,2 ,3, &gs1, 1, NULL);
 
        if(TEST_DEBUG) printGameState(player,&gs1);
		if(choice1 == 1){
        	rslt1 = rslt1 + testAssert((pHand == gs1.handCount[player]- 1),"Hand Compare - Choice = 1");// 2 cards in 1 card out
		} else if(choice1  == 2) {
 		   	rslt1 = rslt1 + testAssert((pCoins == gs1.coins-2),"Coin Compare - Choice = 2");// 2 cards in 1 card out
		}else{
 		   	rslt1 = rslt1 + testAssert((pHand == gs1.handCount[player]+3),"Discard Compare - Choice = 3");// Discard 2 cars plus discard steward
		}
   }
   printf("***   Steward Test Results   ***\nHand Compare - Choice 1: %d of %d Passed\nCoin Compare - Choice 2: %d of %d Passed\nDiscard Compare - Choice 2: %d of %d Passed\n\n", handChoice1, NUM_TEST, coinChoice1, NUM_TEST, rslt1, NUM_TEST);
   
}