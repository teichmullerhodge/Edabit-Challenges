#define NEWLINE         puts("")
#define MAX_LEN_MESSAGE 128
#define MAX_LEN_KEYWORD 64
#define EN_ALPHABET_LEN 26
#define VIGENERE_TABLE  676

size_t NumberSpaces = 0;

char VigenereTable[VIGENERE_TABLE]; int Columm[EN_ALPHABET_LEN];

char *StrToPlain(char *usr), *KeyToPlain(char *Key, char *Keyword, size_t len),
      *CypherVigenere(char *Message, size_t len, char *keyword, char *Encrypted),
       *RotateArrLeft(char *Array, size_t Arrlen),
        *RotateArrRight(char *Array, size_t Arrlen);




int *GetPositions(int *NumArray, size_t OrgLen, char *PlainText,  size_t NoSpaceLen), 
        *RotateLeft(int *Array, size_t Arrlen),
            *RotateRight(int *Array, size_t Arrlen);


void InitVigenereTable(void){

    char Alphabet[EN_ALPHABET_LEN] = {'A','B','C','D','E','F','G','H','I',
                                      'J','K','L','M','N','O','P','Q','R',
                                      'S','T','U','V','W','X','Y','Z'};

    static int VigChars = 0;
    
    for(int k = 0; k < EN_ALPHABET_LEN; k++){
    if(k > 0) RotateArrLeft(Alphabet, EN_ALPHABET_LEN);

    for(int j = 0; j < EN_ALPHABET_LEN; j++){
        VigenereTable[VigChars] = Alphabet[j];
        VigChars++;
    }
 }


    int ColummValues = 0;
    for(int j = 0; j < EN_ALPHABET_LEN; j++){
        Columm[j] = ColummValues;
        ColummValues += EN_ALPHABET_LEN;
    }
}
    


int *RotateLeft(int *Array, size_t Arrlen){

	int keepvalue = Array[0];

	for(int j = 0; j < Arrlen; j++){
		if(j + 1  == Arrlen){ 
			
			Array[j] = keepvalue;
			break;

		}

			Array[j] = Array[j+1];
	}

			return Array;
}

int *RotateRight(int *Array, size_t Arrlen){
	
	int keepvalue = Array[Arrlen - 1];
	for(int k = Arrlen - 1; k >= 0; k--){
		if(k == 0){

			Array[0] = keepvalue;
		}
			else{

			Array[k] = Array[k-1];
		
		}
		
			return Array;

	}
}

char *RotateArrLeft(char *Array, size_t Arrlen){

	int keepvalue = Array[0];
	for(int j = 0; j < Arrlen; j++){
		if(j + 1  == Arrlen){ Array[j] = keepvalue;
			break;
		}

			Array[j] = Array[j+1];
	}

    		return Array;


	}

	char *RotateArrRight(char *Array, size_t Arrlen){
	
	int keepvalue = Array[Arrlen - 1];
	for(int k = Arrlen - 1; k >= 0; k--){
		if(k == 0){

			Array[0] = keepvalue;
		}
			else{

			Array[k] = Array[k-1];
		
		}
		


	}

			return Array;
}

int *GetPositions(int *NumArray, size_t OrgLen, char *PlainText,  
                        size_t NoSpaceLen){

        int position = 1;        
        int letter = -1;
        int ArrayPos = 0;

        for(int j = 0; j < OrgLen; j++){
            position = 1;
            letter++;
        for(size_t k = 0; k <= EN_ALPHABET_LEN; k++){
            if(PlainText[letter] == '\a') letter++;
            if(PlainText[letter] == VigenereTable[k]) break;
            position++;
        }
            NumArray[ArrayPos] = position;
            ArrayPos++;
        
        }

            for(int k = 0; k < NoSpaceLen; k++){
            }

            return NumArray;
}

char *StrToPlain(char *usr){
        
        //removing spaces and changing to uppercase
        for(size_t k = 0; k < strlen(usr); k++){

            if(usr[k] >= 65 && usr[k] <= 90) continue;
            if(usr[k] >= 97 && usr[k] <= 122) usr[k] -= 32;
            else{ 
                
                usr[k] = '\a';  
            }
        }

        
        for(size_t k = 0; k < strlen(usr); k++){
            if(usr[k] == '\a') NumberSpaces++;
        }


        return usr;

}

char *KeyToPlain(char *Key, char *Keyword, size_t len){

            int count = 0;
            for(size_t k = 0; k < len; k++){
                if(Keyword[count] == '\0') count = 0;
                Key[k] = Keyword[count];
                count++;
                
            }

                return Key;
}

