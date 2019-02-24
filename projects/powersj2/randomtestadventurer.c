/**
 * Jake Powers 
 * Random test for dominion function Adventurer()
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
    state->handCount[p] = rand() % MAX_DECK; 
    state->deckCount[p] = rand() % MAX_HAND; 
        return 0;
}

int main(){
    srand(time(NULL));
    int kc[10]= {silver, gold, council_room, baron, minion, treasure_map, tribute, embargo, adventurer, cutpurse};
    struct gameState gs1;
    int randomSeed = 10;
    int rslt1 = 0;
    int rslt2 = 0;
    printf("***  Starting Adventurer Random Tests  ***\n");

   for(int i = 0; i <NUM_TEST; i++){
        initializeGame(rand() % (MAX_PLAYERS - 1)+2, kc, randomSeed, &gs1);
        gs1.whoseTurn = rand() % (gs1.numPlayers); // Set random player
        int player = gs1.whoseTurn;
       if(TEST_DEBUG) printGameState(player,&gs1);
        setupGame(player, &gs1); // Set the players stats to random values
        if(TEST_DEBUG) printGameState(player,&gs1);

        int pHand = gs1.handCount[player];
        int pDeck = gs1.deckCount[player];
        cardEffect(adventurer, 1,2,3, &gs1, 1, NULL);
        if(TEST_DEBUG) printGameState(player,&gs1);

        rslt1 = rslt1 + testAssert((pHand == gs1.handCount[player]-2),"Hand Compare");// Check that previous deck equals discard deckcount and two cards from adventurer
        rslt2 = rslt2 + testAssert((pDeck == gs1.discardCount[player] + gs1.deckCount[player]+2),"Deck Compare");
   }
   printf("***   Adventurer Test Results   ***\nHand Compare: %d of %d Passed\nDeck Compare: %d of %d Passed\n\n", rslt1, NUM_TEST, rslt2, NUM_TEST);
}