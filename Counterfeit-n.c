#include <stdio.h>
#include <stdlib.h>

/**
* Author: Saad Iqbal
* Created: 06/03/2021
* Revised:
* Description: A counterfeit coin problem for coins greater than 8
* User advice: none
*/

/**
* Function: cointerfeit()
* Description: The function is a modified form of Ternary search and find counterfeit by divide and conquer strategy. The division is made in 3 groups
* Parameters: An array of struct Coin with it's size
* Returns: counterfeit index
* Warnings: none
*
*/
int counterfeit(int coins[], int size)
{
    int start = 0, end = size;
    while (end >= start) {

        int leftPan = 0, rightPan = 0;
        int mid1 = start + (end - start) / 3; //First mid 
        int mid2 = end - (end - start) / 3; //Second mid

        // Check if key is present at any mid
        if (coins[mid1] == 0) {
            return mid1;
        }
        if (coins[mid2] == 0) {
            return mid2;
        }
        //Calculate left pan weight

        for (int i = start; i < mid1; i++) {
            leftPan += coins[i];
        }

        //calculate right pan weight

        for (int j = mid2; j < end; j++) {
            rightPan += coins[j];
        }

        if (leftPan < rightPan) {

            //The counterfeit coin is between mid 1 and mid 2
            end = mid1 - 1;
        }
        else if (leftPan > rightPan) {

            // The counterfeit coin lies in between mid2 and r
            start = mid2 + 1;
        }
        else {

            // The counterfeit coin lies in between mid1 and mid2
            start = mid1 + 1;
            end = mid2 - 1;
        }
    }

    // coin not found
    return -1;
}

int main() {

    int coins[30] = { 0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    printf("The counterfeit coin index is: %d\n", counterfeit(coins, 30));
    return 0;
}