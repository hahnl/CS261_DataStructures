/* CS261- Assignment 1 - Q. 0*/
/* Name: Larissa Hahn
 * Date: 04-09-15
 * Solution description: This program declares an integer x, prints its address,
 * and passes its address to a function foo(). Inside foo(), the program
 * then prints the value of x, the address x points to, and the address of x itself
 * using a local pointer to an integer, *iptr. Then back in main, it prints
 * the value of x again.
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("%d\n\n", *iptr);

     /*Print the address pointed to by iptr*/
     printf("%p\n\n", iptr);

     /*Print the address of iptr itself*/
     printf("%p\n\n", &iptr);
}

int main(){

    /*declare an integer x*/
    int x;

    /*print the address of x*/
    printf("%p\n\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("%d\n\n", x);

    return 0;
}
