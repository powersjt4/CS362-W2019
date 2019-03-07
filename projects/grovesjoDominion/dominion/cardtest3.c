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


int main(){
    int kc[10]= {silver, gold, council_room, baron, minion, treasure_map, tribute, embargo, adventurer, cutpurse};
    struct gameState gs1;
    initializeGame(2, kc, 100, &gs1);
    int p0Hand = gs1.handCount[0];
    int p1Hand = gs1.handCount[1];
    int p0Deck = gs1.deckCount[0]; 
    int p1Deck = gs1.deckCount[1];
       
    cardEffect(council_room, 1,2,3, &gs1, 1, NULL);
    
    TEST_ASSERT(gs1.handCount[0] == p0Hand + 3); 
    TEST_ASSERT(gs1.handCount[1] == p1Hand + 1); 
    TEST_ASSERT(gs1.deckCount[0] == p0Deck - 4); 
    TEST_ASSERT(gs1.deckCount[1] == p1Deck - 1); 

    printf("*** End of council_room() tests ***\n\n");

}
