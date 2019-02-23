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


}