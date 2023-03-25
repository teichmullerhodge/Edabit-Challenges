/* DIFFICULTY: MEDIUM

Write a function that takes an array of numbers and returns an array with two elements:

The first element should be the sum of all even numbers in the array.
The second element should be the sum of all odd numbers in the array.
Example
sumOddAndEven([1, 2, 3, 4, 5, 6]) ➞ [12, 9]
// 2 + 4 + 6 = 12 and 1 + 3 + 5 = 9

sumOddAndEven([-1, -2, -3, -4, -5, -6]) ➞ [-12, -9])

sumOddAndEven([0, 0]) ➞ [0, 0])

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //used for generate random numbers for the array
#define CEIL 50

int* sumOddAndEven(int* Array);

int main(void){

    srand(time(NULL));
    int ARR_LEN = 1;
    ARR_LEN += random() % 8;
    int SampleArray[ARR_LEN];
    SampleArray[ARR_LEN] = -1; 
    for(size_t k = 0; k < ARR_LEN - 1; k++){

        SampleArray[k] = random() % CEIL;
        printf("%d ", SampleArray[k]);
    } 
    puts("");
    int* SumEvenOdd;    
    SumEvenOdd = sumOddAndEven(SampleArray);    
    printf("Sum of even numbers is: %d\nSum of odd numbers is %d\n", SumEvenOdd[0], SumEvenOdd[1]);
    return 0;
}

int* sumOddAndEven(int* Array){

    static int EvenOdd[2];
    int k, sum_even, sum_odd = 0;
    
    while(Array[k] <= CEIL && Array[k] >= 0){

        if(Array[k] % 2 == 0) sum_even += Array[k];
        else sum_odd += Array[k];
        k++;

    }
        EvenOdd[0] = sum_even;
        EvenOdd[1] = sum_odd;

        return EvenOdd;

    
}

