/**
 * Jake Powers 
 * Unit test for dominion function smithyCard()
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

 /*Setup initial values to control game flow*/
int setupGame(int p, struct gameState *state){
    state->handCount[p] = 2; 
    state->deckCount[p] = 5;
    state->discardCount[p] = 0;
    state->deck[p][0] = curse; //Stack the deck
    state->deck[p][1] = silver;
    state->deck[p][2] = curse;
    state->deck[p][3] = gold;
    state->deck[p][3] = baron;
    state->hand[p][0] = silver;
    state->hand[p][1] = smithy;
    state->whoseTurn = 1; // Set tp player 1
    return 0;
}
 
int main(){
  int kc[10]= {silver, gold, council_room, baron, minion, treasure_map, tribute, embargo, adventurer, cutpurse};
  struct gameState gs1;
  int player = 1;
  initializeGame(2, kc, 100, &gs1);
  setupGame(player, &gs1);
  cardEffect(smithy,1,2,3,&gs1,1, NULL);
  TEST_ASSERT(gs1.deckCount[player] == 2); // 3 cards drawn from deck 
  TEST_ASSERT(gs1.handCount[player] == 4);  // Hand now contains three drawn cards

  printf("*** End of smithyCard() tests ***\n\n");

}
