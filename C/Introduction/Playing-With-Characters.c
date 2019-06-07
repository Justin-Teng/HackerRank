#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char c;
    scanf("%c", &c);
    
    char string[256];
    scanf("%s", string);
    scanf("\n");

    char* sentence = NULL;
    size_t size;
    getline(&sentence, &size, stdin);

    printf("%c\n", c);
    printf("%s\n", string);
    printf("%s\n", sentence);
    return 0;
}

