/* CS261- Assignment 1 - Q.5*/
/* Name: Larissa Hahn
 * Date: 04-12-15
 * Solution description: Convert a word to sticky caps.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word) {
     /*Convert to sticky caps*/
     int i;
     for (i=0; i<strlen(word); i++) { // For each character in string
        if ((i%2) == 0) { // If that character is in Even position beginning with first character of string
           if (!isupper(word[i])) { // toUpperCase assumes it begins with lowercase
              word[i] = toUpperCase(word[i]); // capitalize it
           }
        }
        else if ((i%2) == 1) { // For the odd characters
           if (!islower(word[i])) { // toLowerCase assumes it beings with Uppercase
              word[i] = toLowerCase(word[i]); // make it toLowerCase
           }
        }
     }
}

int main(){
    /*Read word from the keyboard using scanf*/

    char *wordString = (char*)malloc(sizeof(char));
    printf("Enter a word to convert to sticky caps: ");
    scanf("%s", wordString);
    printf("\n");

    /*Call sticky*/
    sticky(wordString);

    /*Print the new word*/
    printf("Your new word:  %s\n\n", wordString);

    /* Free memory */
    free (wordString);

    return 0;
}
