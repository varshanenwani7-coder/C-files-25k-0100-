#include <stdio.h>
#include <string.h>

#define BIT2 (1 << 1)
#define BIT5 (1 << 4)

void reverseString(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void encodeMessage(char msg[]) {
    reverseString(msg); 
    int i;
    for (i = 0; i < strlen(msg); i++) {
        msg[i] = msg[i] ^ BIT2 ^ BIT5; 
    }
    printf("\nEncoded Message: %s\n", msg);
}

void decodeMessage(char msg[]) {
	int i;
    for (i = 0; i < strlen(msg); i++) {
        msg[i] = msg[i] ^ BIT2 ^ BIT5; 
    }
    reverseString(msg); 
    printf("\nDecoded Message: %s\n", msg);
}

int main() {
    char message[200];
    int choice;

    while (1) {
        printf("\n--- TCS Secure Message Tool ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
        case 1:
            printf("Enter message to encode: ");
            gets(message);
            encodeMessage(message);
            break;
        case 2:
            printf("Enter message to decode: ");
            gets(message);
            decodeMessage(message);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}

