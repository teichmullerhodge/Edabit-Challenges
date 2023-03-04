#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ARGERROR_ "Usage: <password>\n"

int MinChanges(char *pass); 

bool Hasdigit(char *pass), isLower(char *pass), isUpper(char *pass), RepRow(char *pass);


int main(int argc, char *argv[]){

    if(argc!=2){
        printf(ARGERROR_);
        exit(0);
    }
    int x = MinChanges(argv[1]);
    printf("%d\n", x);
}


int MinChanges(char *pass){
    
    int changes = 0;

    if (Hasdigit(pass) == 0) changes++;
    if (isLower(pass) == 0 ) changes++;
    if (isUpper(pass) == 0)  changes++;
    if (strlen(pass) == 7 && changes == 1) return 1;
    if (strlen(pass) < 8)  changes += 8 - strlen(pass) - changes;
    if (strlen(pass) > 20) changes += strlen(pass) - 20 - changes;
    if (RepRow(pass) == 1) changes++;

    return changes;

}


bool Hasdigit(char *pass){

    for(int j = 0; j < strlen(pass); j++){
        if(pass[j] >= 48 && pass[j] <= 57) return true;
    }

    return false;
}

bool isUpper(char *pass){

    for(int j = 0; j < strlen(pass); j++){
        if(pass[j] >= 65 && pass[j] <= 90) return true;
    }

    return false;
}

bool isLower(char *pass){

    for(int j = 0; j < strlen(pass); j++){
        if(pass[j] >= 97 && pass[j] <= 122) return true;
    }

    return false;

}

bool RepRow(char *pass){

        for(int k = 0; k < strlen(pass); k++){
            if(pass[k] == pass[k+1] && pass[k+1] == pass[k+2] && k+2 < strlen(pass)) return true;
        }

        return false;
}
           