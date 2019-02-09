/**
 * Jake Powers 
 * Unit test for dominion function buyCard()
 * 2.9.19
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Shamelessly Lifted from http://www.dillonbhuff.com/?p=439*/
#define STR(x) #x
#define TEST_ASSERT(x) if (!(x)) {printf("Assertion failed:(x) (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}else{printf("Pass: (\xE2\x9C\x93)\n");}

int main(){
    int supplyPos = 0;
    struct gameState gs;
    gs.numBuys = 0;
    //Test first condition no more buys
    TEST_ASSERT(buyCard(supplyPos , &gs) == -1);
    //Test not enough coins to buy card
    gs.coins = 2;
    gs.numBuys = 1;
    //adventurer = 6 cost
    supplyPos = adventurer;
    TEST_ASSERT(buyCard(supplyPos , &gs) == -1);
    //There are enough coins but none of that card
    gs.coins = 6;
    gs.supplyCount[adventurer] = 0;
    TEST_ASSERT(buyCard(supplyPos , &gs) == -1);
    
    gs.supplyCount[adventurer] = 1;
    //Positive case successfully add card to hand
    TEST_ASSERT(buyCard(supplyPos , &gs) == 0);
    TEST_ASSERT(gs.coins == 0);//All coins gone
    TEST_ASSERT(gs.supplyCount[adventurer] == 0);// Card supply empty
    TEST_ASSERT(gs.phase == 1);
   
    printf("*** End of buyCard() tests ***\n\n");
}