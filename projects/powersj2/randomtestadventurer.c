/**
 * Jake Powers 
 * Random test for dominion function shuffle()
 * 2.23.19
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h> // for rand(seed)


/*Shamelessly Lifted from http://www.dillonbhuff.com/?p=439*/
#define STR(x) #x
#define TEST_ASSERT(x) if (!(x)) {printf("Assertion failed:(x) (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}else{printf("Pass: (\xE2\x9C\x93)\n");}
#define NUM_TEST 2

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
    initializeGame(rand() % (MAX_PLAYERS - 1)+2, kc, randomSeed, &gs1);
    gs1.whoseTurn = rand() % (gs1.numPlayers); // Set random player
    int player = gs1.whoseTurn;
    printGameState(player,&gs1);
    setupGame(player, &gs1); // Set the players stats to random values
    printGameState(player,&gs1);

    int pHand = gs1.handCount[player];
    int pDeck = gs1.deckCount[player];
    cardEffect(adventurer, 1,2,3, &gs1, 1, NULL);
    printGameState(player,&gs1);

    TEST_ASSERT(pHand == gs1.handCount[player]-2);// 2 treasure cards
    TEST_ASSERT(pDeck == gs1.discardCount[player] + gs1.deckCount[player]+2); // Check that previous deck equals discard deckcount and two cards from adventurer
}