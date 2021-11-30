/**
 * @file bsearch.c
 * @version 0.1
 * @date 2021-11-29
 */

#include <stdio.h>
#include <conio.h>

#define true 1
#define false 0


int binary_search(int array[], int left, int right, int x) 
{
    //cond
    int is_present_in_right = false;
    int is_present_in_left = false;
    int is_present_in_middle = false;

    if(right >= 1) 
    {
        /*** if value X matches the middle element, we shall return the 
         *   middle element
         ***/
        int middle = left + (right - 1) / 2;
        if(array[middle] == x) 
        {
            is_present_in_middle = true;
            return middle;
        }

        /*** if value X is smaller than middle, 
         *   X shall only be in the left half of this array.
         * ***/ 
        if(array[middle] > x) 
        {
            is_present_in_left = true;
            return binary_search(array, left, middle - 1, x);
        }

        /*** if value X is larger than middle, 
         *   X shall only be in the right half of this array.
         * ***/ 
        else {
            is_present_in_right = true;
            return binary_search(array, middle + 1, right, x);
        }

        if(
            !is_present_in_right&&
            !is_present_in_left &&
            !is_present_in_middle) 
        {
            goto death;
        }
    }


    /***********************************************************/
    // if the element simply does not exist, we will return -1,
    // as an indication that X does not lie within the array. 
    /***********************************************************/
death:
    printf("\n!!%d not present within provided array.", x);
    return -1;

}

int main(int argc, char* argv) 
{

/*  int array[] = {0, 1, 2, 4, 3, 4, 5};
    int wanted = 6;
    int arraySize = sizeof(array)/ sizeof(array[0]);
    binary_search(array, 0, arraySize-1, wanted);
*/
    getch();
}