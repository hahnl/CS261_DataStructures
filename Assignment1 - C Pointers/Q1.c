/* CS261- Assignment 1 - Q.1*/
/* Name: Larissa Hahn
 * Date: 04-09-15
 * Solution description: This program allocates memory for ten
 * students' scores that correspond to ten student IDs and generates
 * these scores randomly. It then prints the maximum score, minimum
 * score, and average score for each student ID. Finally it frees
 * the memory allocated.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	 int id;
	 int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* students = malloc(10*sizeof(struct student));

     /*return the pointer*/
     return students;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int i;
     for (i=0; i<10; i++) {
        students[i].id = i+1; // Unique ID, Random IDs don't make sense
        students[i].score =(rand()%100+1); //max+min
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
     int i;
     for(i=0; i<10; i++) {
        printf("Student ID# %d = %d score.\n", students[i].id, students[i].score);
     }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int scores; // Local variables. C requires declare separately
     int total; // Accumulate scores
     int minimum;
     int maximum;

     //Assign values
     scores = 10; // Total number of scores. Same as number of students.
     minimum = 100; // Minimum must be less than 100
     maximum = 0; // Maximum must be greater than 0

     int i; // C requires do separate
     for (i=0; i<scores; i++) {
        if (students[i].score > maximum) { // Check for new maximum
           maximum = students[i].score;
        }
        if (students[i].score < minimum) { // Check for new minimum
           minimum = students[i].score;
        }
        total += students[i].score;
     }
     int average; // Compute average:
     average = total/scores;

     printf("\n\nRESULTS:\n"); // Print results
     printf("-------------\n");
     printf("Minimum is %d.\n", minimum);
     printf("Maximum is %d.\n", maximum);
     printf("Average is %d.\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if (stud != NULL) {
        free(stud);
     }
}

int main(){
     struct student* stud = NULL;

     /*call allocate*/
     stud = allocate();

     /*call generate*/
     generate(stud);

     /*call output*/
     output(stud);

     /*call summary*/
     summary(stud);

     /*call deallocate*/
     deallocate(stud);

    return 0;
}
