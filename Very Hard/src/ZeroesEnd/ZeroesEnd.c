/*Write a function that moves all the zeroes to the end of an array. 
Do this without returning a copy of the input array.

Examples
zeroesToEnd([1, 2, 0, 0, 4, 0, 5]) ➞ [1, 2, 4, 5, 0, 0, 0]

zeroesToEnd([0, 0, 2, 0, 5]) ➞ [2, 5, 0, 0, 0]

zeroesToEnd([4, 4, 5]) ➞ [4, 4, 5]

zeroesToEnd([0, 0]) ➞ [0, 0]

Notes:

- You must mutate the original array.
- Keep the relative order of the non-zero elements the same.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* zeroesToEnd(int* Array);

int main(void){

            srand(time(NULL));
            size_t ArrayLen = 2;
            ArrayLen += random() % 9; //MINIMUM NUMBER OF ELEMENTS
            int Array[ArrayLen];
            printf("Array before the transformation: ");
            for(size_t k = 0; k < ArrayLen - 1; k++){
               Array[k] = random() % 10;
               printf("%d ", Array[k]); //ARRAY BEFORE THE TRANSFORMATION
            }
               puts("");
               Array[ArrayLen] = -1; //PAD -1 TO THE END OF THE ARRAY SO WE CAN FIND THE LENGTH WITH ONLY ONE PARAMETER 
               zeroesToEnd(Array);   
               puts("");
               return 0;
}


int* zeroesToEnd(int* Array){


            size_t len = 0;
            while(Array[len] != -1) len++;
            int A_tochange[len];
            int counter = 0;

            for(size_t m = 0; m < len - 1; m++){
             A_tochange[m] = 0;
             if(Array[m] != 0){
                A_tochange[counter] = Array[m];
                counter++;
                  }

            }
               printf(" Array after the transformation: ");
              for(size_t t = 0; t < len - 1; t++){
               Array[t] = A_tochange[t];
               printf("%d ", Array[t]); //ARRAY AFTER THE TRANSFORMATION
              
           
              }

              return Array;

}



