/* CS261- Assignment 1 - Q.3*/
/* Name: Larissa Hahn
 * Date: 4-12-15
 * Solution description: This program dynamically allocates an array
 * of integers, sorts that array in ascending order, then prints the
 * new order of the array.
 */

#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n) {
    /*Sort the given array number , of length n*/
    int tempNum; // Local variable

    for (int i=0; i<n; i++) { // For each number
       tempNum = number[i];
       for (int j=i+1; j<n; j++) {  // Sort numbers ascending order
          if ((number[j]) < tempNum) // If next number is less than current number
          {
             number[i] = number[j]; // Current number becomes next (they swap places)
             number[j] = tempNum; // That next number takes the current number position/place (they swap places)
             tempNum = number[i]; // Now temp variable for swap gets updated to the current position
          }
       }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *intArray = (int*)malloc(sizeof(int)*n);

    /*Fill this array with random numbers, using rand().*/
    for (int i=0; i<n; i++) {
       intArray[i] = rand()%1000+1; //max+min
    }

    /*Print the contents of the array.*/
    for (int i=0; i<n; i++) {
       printf("%d\n", intArray[i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(intArray, n);
    printf("\n");

    /*Print the contents of the array.*/
    for (int i=0; i<n; i++) {
       printf("%d\n", intArray[i]);
    }

    return 0;
}
