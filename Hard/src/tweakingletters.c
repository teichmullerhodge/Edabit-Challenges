#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Usage(void){

        puts("Usage: <string>");
        exit(-1);

}

char *TweakingLetters(char *Usr, int *binArray);

int *init_array(int *arr, size_t len);

int main(int argc, char *argv[]){

        if(argc!=2) Usage();
        srand(time(NULL));

        size_t len = strlen(argv[1]);

        int binArray[len];

        init_array(binArray, len);
        TweakingLetters(argv[1], binArray);
        return 0;
}

int *init_array(int *arr, size_t arrlen){
        
        printf("{ ");  int RNG;

        for(int k = 0; k < arrlen; k++){

            init:
            RNG = random() % 8;

            if(k == arrlen) goto out;
            if(RNG < 3 && k < arrlen){ arr[k] = 1;
                printf("%d ", arr[k]);
                k++;
                goto init;

            }
            
            if(RNG < 6 && k < arrlen){ arr[k] = -1;
                printf("%d ", arr[k]);
                k++;
                goto init;
            }   

            if(RNG < 9 && k < arrlen){ arr[k] = 0;
            printf("%d ", arr[k]);
                k++;
                goto init;

            }

            out:
            printf(" }\n");

}

}

char *TweakingLetters(char *Usr, int *binArray){

                    size_t Mylen = strlen(Usr); 
                                                
                    int Ascii;

                    for(int k = 0; k < Mylen; k++){
                        
                        Ascii = Usr[k];

                        if(binArray[k] == 0) Usr[k] = Usr[k];
                    
                        if(binArray[k] == 1) Usr[k] = Ascii+1;
                        
                        if(binArray[k] == -1) Usr[k] = Ascii-1;


                        if(Ascii == 97  && binArray[k] == -1) Usr[k] = 'z';

                        if(Ascii == 65  && binArray[k] == -1) Usr[k] = 'Z'; 

                        if(Ascii == 122 && binArray[k] ==  1) Usr[k] = 'a';

                        if(Ascii == 90 && binArray[k] ==  1) Usr[k] = 'A';

                        //a in ascii is 97
                        //A in ascii is 65
                        //z in ascii is 122
                        //Z in ascii is 90 

                    }

                    for(int j = 0; j < Mylen; j++){
                            printf("%c", Usr[j]);
                    }
                    
                    puts("");
}