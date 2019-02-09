/**
 * Jake Powers 
 * Unit test for dominion function getCost()
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
    printf("*** Test function getCost() ***\n");
    TEST_ASSERT(getCost(curse)==0);
    TEST_ASSERT(getCost(estate)==2);
    TEST_ASSERT(getCost(duchy)==5); 
    TEST_ASSERT(getCost(province)==8);
    TEST_ASSERT(getCost(copper)==0);

    TEST_ASSERT(getCost(silver)==3);
    TEST_ASSERT(getCost(gold)==6);
    TEST_ASSERT(getCost(adventurer)==6); 
    TEST_ASSERT(getCost(council_room)==5);
    TEST_ASSERT(getCost(feast)==4);

    TEST_ASSERT(getCost(gardens)==4);
    TEST_ASSERT(getCost(mine)==5);
    TEST_ASSERT(getCost(remodel)==4); 
    TEST_ASSERT(getCost(smithy)==4);
    TEST_ASSERT(getCost(village)==3);

    TEST_ASSERT(getCost(baron)==4);
    TEST_ASSERT(getCost(great_hall)==3); 
    TEST_ASSERT(getCost(minion)==5);
    TEST_ASSERT(getCost(steward)==3);
    TEST_ASSERT(getCost(tribute)==5);
    
    TEST_ASSERT(getCost(ambassador)==3);
    TEST_ASSERT(getCost(cutpurse)==4); 
    TEST_ASSERT(getCost(embargo)==2);
    TEST_ASSERT(getCost(outpost)==5);
    TEST_ASSERT(getCost(salvager)==4);

    TEST_ASSERT(getCost(sea_hag)==4);
    TEST_ASSERT(getCost(treasure_map)==4); 
    TEST_ASSERT(getCost(42)==-1);    
    
    printf("*** End of getCost() tests ***\n\n");
    
}