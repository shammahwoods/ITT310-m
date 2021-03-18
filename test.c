#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {

    char str[60];
    printf("Enter a value :");

    gets(str);
    printf("\nYou entered: ");

    puts(str);

    return 0;
}