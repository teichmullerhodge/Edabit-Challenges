/*The Collatz sequence is as follows:

Start with some given integer n.
If it is even, the next number will be n divided by 2.
If it is odd, multiply it by 3 and add 1 to make the next number.
The sequence stops when it reaches 1.
According to the Collatz conjecture, it will always reach 1. 
If that's true, you can construct a finite sequence following the aforementioned method for any given integer.
Write a function that takes in an integer n and returns the highest integer in the corresponding Collatz sequence.

*/


#include <iostream>
#include <cstdlib>
#define CEIL 999999

using namespace std;

int Collatz(int N), MaxCollatz(int N);

int main(void){

    srand((unsigned) time(NULL));
    int N = random() % CEIL;
    N += 10; //Minimum value of N, lol
    int res = Collatz(N);   
    cout << "Result of iterations is: " << res << endl;
    cout << "Max value of iterations is: " << MaxCollatz(N) << endl;
}

int Collatz(int N){
    
    int originalvalue = N;  
    int iteration = 0;

    while(N!=1){
        if(N % 2 == 0){ 
            N/=2;
            iteration++;
            cout << iteration << "-th iteration of " <<  originalvalue << " is " << N << endl; 

                       }
        else{
            N *= 3;
            N++;
            iteration++;
            cout << iteration << "-th iteration of " << originalvalue << " is " << N << endl;    
    }
                        }

            return N;


}


int MaxCollatz(int N){

    unsigned int MAX;
    while(N!=1){
        if(N > MAX) MAX = N;
    if(N % 2 == 0) 
        N/=2;
    else{
        N *= 3;
        N++;
            }
    }

    return MAX;
    
}