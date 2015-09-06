/* CS261- Assignment 1 - Q.4*/
/* Name: Larissa Hahn
 * Date: 04-11-12
 * Solution description: This program sorts an array of n student scores (20)
 * in ascending order. Each score has a Unique Student ID#.
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n) {
     /*Sort the n students based on their score*/
     int tempID, tempScore; // Local variables

     for (int i=0; i<n; i++) { // For each student n
        tempID = (students+i)->id; // with ID (swap placeholder)
        tempScore = (students+i)->score; // and score... (swap placeholder)

        for (int j=i+1; j<n; j++) {  // Sort through scores ascending order
           if ((students+j)->score < tempScore) // If next score is less than current student's
           {
              (students+i)->score = (students+j)->score; // Current student score becomes next (they swap places)
              (students+j)->score = tempScore; // That next score takes the current student place (they swap places)
              tempScore = (students+i)->score; // Now temp variable for swap gets updated to the current score

              (students+i)->id = (students+j)->id; // // Swap IDs same as Scores... next and current swap places if..
              (students+j)->id = tempID;            // // ..if next score to be sorted is less than current.
              tempID = (students+i)->id; // Now temp ID variable for swap gets updated to the current ID
           }
        }
     }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;

    /*Allocate memory for n students using malloc.*/
    struct student *students =(struct student*)malloc(sizeof(struct student)*n);

    /*Generate random IDs and scores for the n students, using rand().*/
    for (int i=0; i<n; i++) {
       (students+i)->id = i+1; // Random ID doesn't make sense, used Unique ID
       (students+i)->score =rand()%100+0; //max+min
    }

    /*Print the contents of the array of n students.*/
    int i;
    for (i=0; i<n; i++) {
       printf("Student ID%d = score %d.\n", (students+i)->id, (students+i)->score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    printf("\n");

    /*Print the contents of the array of n students.*/

    for (i=0; i<n; i++) {
       printf("Student ID%d = score %d.\n", (students+i)->id, (students+i)->score);
    }

    return 0;
}
