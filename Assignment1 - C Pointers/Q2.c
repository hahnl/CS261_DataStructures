/* CS261- Assignment 1 - Q.2*/
/* Name: Larissa Hahn
 * Date: 04-09-15
 * Solution description: This program prints three integers: 5, 6, 7. Then
 * a function is called which doubles 5(10), halves 6(3), and alters a variable
 * for an integer c which is the sum of 10+3. C is then returned to main and
 * different from the variable z which was never passed by reference.
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = (*a)*2;

    /*Set b to half its original value*/
    *b = (*b)/2;

    /*Assign a+b to c*/
    c = (*a)+(*b);

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int result = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("%d\n\n", result);

    /*Print the values of x, y and z again*/
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n\n", z);

    /*Is the return value different than the value of z?  Why?
    Answer: Variable z gets passed to the foo() function by value instead
    of by reference; therefore, the function never actually changes the
    original variable z. So they result is different from variable z
    which remains unchanged.
    */

    return 0;
}
