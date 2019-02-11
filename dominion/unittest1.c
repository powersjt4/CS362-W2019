/**
 * Jake Powers 
 * Unit test for dominion function shuffle()
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
    struct gameState gs;
    int player = 1;
    int cardsInOrderCheck = 0;
    gs.deckCount[player] = 0;
    printf("** Testing shuffle() **\n");
    //TEST_ASSERT(shuffle(player, &gs) == -1);
    TEST_ASSERT(shuffle(player, &gs) == -1);
    gs.deckCount[player] = MAX_DECK; //Create new deck

    for(int i = 0; i < MAX_DECK; i++){
        gs.deck[player][i] = i; //Set deck values sequentially 
    }
    TEST_ASSERT(shuffle(player, &gs)==0);//Shuffle deck to randomize values
    for(int i = 0; i < MAX_DECK; i++){
        if(gs.deck[player][i] == i){ //Check that values are not in order
            cardsInOrderCheck++;
        }else{
            cardsInOrderCheck=0;
        }
        if(cardsInOrderCheck == MAX_DECK -1){
            TEST_ASSERT(0);
        }
    }
    return 0;

    printf("*** End of shuffle() tests ***\n\n");

}