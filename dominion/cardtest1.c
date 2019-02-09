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
    state->deck[p][0] = curse;
    state->deck[p][1] = silver;
    state->deck[p][2] = curse;
    state->deck[p][3] = gold;
    return 0;
}
 
int main(){
    struct gameState gs1;

    int player = 1;
  /*Setup initial values to control game flow*/

    setupGame(player, &gs1);
    TEST_ASSERT(adventurerCard(player, 1, &gs1) == 0); //Assert that function is called successfully
    TEST_ASSERT(gs1.deckCount[player] == 1); // 4 cards drawn from deck 
    TEST_ASSERT(gs1.discardCount[player] == 2); // Discard pile contains two curse cards
    TEST_ASSERT(gs1.handCount[player] == 12);  // Hand now contains two treasure playedCards

    printf("*** End of adventurerCard() tests ***\n\n");

}
