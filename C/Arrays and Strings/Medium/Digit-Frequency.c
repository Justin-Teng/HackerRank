#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s = malloc(1000 * sizeof(char));
    scanf("%s", s);
    s = realloc(s, strlen(s)+1);

    int *freqs = malloc(10 * sizeof(int));
    for (int i = 0; i < strlen(s); i++) {
        int d = s[i] - '0';
        freqs[d]++;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d", freqs[i]);
        if (i != 9)
            printf(" ");
    }

    free(s);
    return 0;
}
