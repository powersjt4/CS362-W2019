/**
 * Jake Powers 
 * Unit test for dominion function isGameOver()
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
    struct gameState gs;
    gs.supplyCount[province] = 0;
    printf("*** Testing isGameOver() ***\n");
    TEST_ASSERT(isGameOver(&gs) == 1);  //Test case 1 province cards are empty 

    /*Positive test case ie. game is not over*/
    gs.supplyCount[province] = 100;
    for(int i = 0; i < 25; i++){ //Set all supply counts to > 0;
        gs.supplyCount[i] = 100;
    }
    TEST_ASSERT(isGameOver(&gs) == 0);
  
   /* Set province cards > 0 and first supplies all to 0 */
    gs.supplyCount[province] = 1; 
    gs.supplyCount[0] = 0;
    gs.supplyCount[11] = 0;
    gs.supplyCount[23] = 0;
    TEST_ASSERT(isGameOver(&gs) == 1);  //Test case 1 province cards are empty 

    printf("*** End of isGameOver() tests ***\n\n");
}