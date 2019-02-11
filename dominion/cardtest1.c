/**
 * Jake Powers 
 * Unit test for dominion function adventurerCard()
 * 2.9.19
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*Shamelessly Lifted from http://www.dillonbhuff.com/?p=439*/
#define STR(x) #x
#define TEST_ASSERT(x) if (!(x)) {printf("Assertion failed:(x) (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}else{printf("Pass: (\xE2\x9C\x93)\n");}

int setupGame(int p, struct gameState *state){
    state->handCount[p] = 10; 
    state->deckCount[p] = 5; //Needs to be 5 or else shuffle will occur
    state->discardCount[p] = 0;
    state->deck[p][0] = curse; // Stack deck
    state->deck[p][1] = silver;
    state->deck[p][2] = curse;
    state->deck[p][3] = gold;
    state->whoseTurn = 1; // Set player
    return 0;
}

int main(){
    int kc[10]= {silver, gold, council_room, baron, minion, treasure_map, tribute, embargo, adventurer, cutpurse};
    struct gameState gs1;
    initializeGame(2, kc, 100, &gs1);
    int player = 1;
    setupGame(player, &gs1);

    int p1Deck = gs1.deckCount[1];
    int p1Hand = gs1.handCount[1];
    cardEffect(adventurer, 1,2,3, &gs1, 1, NULL);
 
    TEST_ASSERT(gs1.deckCount[player] == p1Deck - 2); // 2 cards drawn from deck 
    TEST_ASSERT(gs1.handCount[player] == p1Hand + 2);  // Hand now contains two treasure playedCards

    printf("*** End of adventurerCard() tests ***\n\n");

}
