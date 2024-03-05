/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE ** WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
** FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR ** OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE ** OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY. */

#include <stdio.h>
#include <stdlib.h>

void encryptHex(char* hexi, char* key, char* cypher, int length) {
    long keyVal;
    int idx = 0;
    char keyExtended[9];

    for (int i = 0; i < 8; i++) {
        keyExtended[i] = key[i % 4];
    }
    keyExtended[8] = '\0';

    keyVal = strtol(keyExtended, NULL, 2);
    
    while (hexi[idx] != '\0') {
        cypher[idx] = hexi[idx] ^ keyVal;
        idx++;
    }
    cypher[idx] = '\0';

    /*modify this loop for unconditional hex printing without formatting*/
    for (int i = 0; i < length; i++) {
        if (cypher[i] == '\n') break;
        printf("%02hhX ", cypher[i]);
    }
    printf("\n");
}

char* readEncryptionKey(char* key) {
    #ifdef PROMPT
    printf("Input 4-bit key (e.g., 0110): ");
    #endif

    for (int index = 0; index < 4; index++) {
        key[index] = getchar();
    }
    /*no need for null termination as we directly use this in binary to long conversion*/
    return key;
}

int main() {
    char inputChar;
    char encryptionKey[5];
    char inputString[200];
    char encryptedString[200];
    int inputLength = 0;

    #ifdef prompt
    printf("Enter a string to be turned into hexadecimal: ");
    #endif

    while ((inputChar = getchar()) != '\n' && inputChar != EOF && inputLength < 199) {
        inputString[inputLength++] = inputChar;
    }
    inputString[inputLength] = '\0';

    /*remove the conditional compilation around hex printing of the input string*/
    for (int i = 0; i < inputLength; i++) {
        printf("%02X ", inputString[i]);
    }
    printf("\n");

    readEncryptionKey(encryptionKey);
    encryptHex(inputString, encryptionKey, encryptedString, inputLength);

    return 0;
}




