#include <stdio.h>
#include <stdlib.h>

/**
* Author: Saad
* Created: 05/03/2021
* Revised: 
* Description: A counterfeit coin problem
* User advice: none
*/

/**
* Function: cointerfeit()
* Description: The function is a modified form of binary search and find counterfeit by divide and conquer strategy.
* Parameters: An array of struct Coin with it's size
* Returns: counterfeit index
* Warnings: none
*
*/
int counterfeit(int coins[], int size)
{
    int start = 0, end = size;
    while (start <= end) {
        int m = start + (end - start) / 2;

        int leftPan = 0, rightPan = 0;
        
        for (int i = start; i <= m; i++) {
            leftPan += coins[i];
        }
        for (int j = m+1; j < end; j++) {
            rightPan += coins[j];
        }
        if (coins[m] == 1)
            return m;

        // If rightPan is greater, ignore left Pan coins 
        if (rightPan > leftPan)
            start = m + 1;
       //if left pan is greater, ignore right pan coins
        else
            end = m - 1;
    }

    // if we reach the end, then countefeit is not in array
    return -1;
}

int main() {

    int coins[8] = { 0,0,0,0,0,1,0,0 };
    printf("The counterfeit coin index is: %d\n", counterfeit(coins, 8));


	return 0;
}