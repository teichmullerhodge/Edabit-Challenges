/*Tap code is a way to communicate messages via a series of taps (or knocks) for each letter in the message.
 Letters are arranged in a 5x5 polybius square, with the letter "K" being moved to the space with "C".

   1  2  3  4  5
1  A  B C\K D  E
2  F  G  H  I  J
3  L  M  N  O  P
4  Q  R  S  T  U
5  V  W  X  Y  Z

Each letter is translated by tapping out the row and column number that the letter appears in, leaving a short pause in-between. 
If we use "." for each tap, and a single space to denote the pause:

text = "break"

"B" = (1, 2) = ". .."
"R" = (4, 2) = ".... .."
"E" = (1, 5) = ". ....."
"A" = (1, 1) = ". ."
"K" = (1, 3) = ". ..."
Another space is added between the groups of taps for each letter to give the final code:

"break" = ". .. .... .. . ..... . . . ..."
Write a function that returns the tap code if given a word, or returns the translated word (in lower case) if given the tap code. 
When translating from tap-code, default to the letter "c" if the tap-code ". ..." is found.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define SYMB_ERR "Symbols are not allowed!\n"

char Knocks[5][5] = {"abcde", 
                     "fghij", 
                     "lmnop", 
                     "qrstu", 
                     "vwxyz"};

int dotTochar(int row, int column);

void tapCode(char *message);

int __putDots(int row, int column);

void Usage(void){

    puts("Usage: <message>"); 
    exit(0);

}

int main(int argc, char *argv[])
{

    if(argc!=2) Usage();
    tapCode(argv[1]);
    return 0;
}


void tapCode(char *message){

        static int ptr[2]; 
        size_t len = strlen(message);
        for(int k = 0; k < len; k++){

        if(message[k] == 46){ //decrypt mode

            ptr[0] = 0; ptr[1] = 0;
            int _index = 0;
            int rowcl = -1; 
            while(k < len){
                rowcl++;
                if(message[k] == 32){
                    ptr[_index] = rowcl;
                    rowcl = -1;
                    if(ptr[_index] != 0 && ptr[_index-1] !=0){ 
                        dotTochar(ptr[_index-1], ptr[_index]);
                        ptr[_index] = 0;
                        ptr[_index-1] = 0;                    
                                }
                    _index++;
                    if(_index > 1) _index = 0;
                                        }

            if(k == len-1){
                ptr[_index] = rowcl+1; 
                dotTochar(ptr[_index-1], ptr[_index]);
                                        }
            k++;
}
            puts("");
            exit(0);
}

    
             
        if(message[k] >= 65 && message[k] <= 90) message[k] += 32; //Handling uppercase
        if(message[k] < 65 || message[k] > 122 || message[k] > 90 && message[k] < 97){ //Not a char
            printf(SYMB_ERR);            exit(0); 
                                          }

            ptr[0] = 1;
            ptr[1] = message[k] - 96;

            if(ptr[1] == 11 /*is 'k'?*/  ){ 
                ptr[0] = 1;
                ptr[1] = 3;
                __putDots(ptr[0], ptr[1]);
                continue;                        } 
            if(ptr[1] > 5 && ptr[1] <= 10){
                ptr[0]++;
                ptr[1] -= 5;        }
            if(ptr[1] > 10 && ptr[1] <= 16){
                ptr[0] += 2;
                ptr[1] -= 11;       }
            if(ptr[1] > 16 && ptr[1] <= 21){
                ptr[0] += 3;
                ptr[1] -= 16;       }
            if(ptr[1] > 21 && ptr[1] <= 26){
                ptr[0] += 4;
                ptr[1] -=21;
                                    }
            __putDots(ptr[0], ptr[1]);
            
        }    

            puts("");
            exit(0);
}

int __putDots(int row, int column){


        for(size_t k = 0; k < row; k++)
            printf(".");
        printf(" ");    
        for(size_t m = 0; m < column; m++)
            printf(".");
        printf(" ");    
        return 0;         
}


int dotTochar(int row, int column){

            printf("%c", Knocks[row-1][column-1]);
            return 0;
}









