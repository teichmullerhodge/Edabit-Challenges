/*Build a function that creates histograms. 
Every bar needs to be on a new line and its length corresponds to the numbers in the array passed as an argument. 
The second argument of the function represents the character to be used for the bar.

histogram(arr, char) ➞ str
Examples
histogram([1, 3, 4], "#") ➞ "#\n###\n####"

#
###
####

histogram([6, 2, 15, 3], "=") ➞ "======\n==\n===============\n==="

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //generate random numbers
#define MAX_NUM 169 //New_line at 1366x768 res (80x24 terminal) 

int k = 0;

void __print(int times, char letter);

void histogram(int *Array, char character);


int main(void){

        srand(time(NULL));
        int Array_len = 1 + random() % 9;
        int histArray[Array_len];
        for(k = 0; k < Array_len; k++){

            histArray[k] = random() % MAX_NUM;
            printf("%d ", histArray[k]);
        }

        puts("");
        char symbols[] = "+-!@#$!*)(0[;"; char letter[1];
        int RNG = random() % 12;
        printf("%d\n", RNG);
        letter[0] = symbols[RNG];
        
        
        histogram(histArray, letter[0]);

        return 0;   
}

void histogram(int *Array, char character){

            for(size_t m = 0; m < k; m++){

                __print(Array[m], character);
            }
}

void __print(int times, char letter){

        for(int i = 0; i < times; i++){
            printf("%c", letter);
        }

        puts("");


}