#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);
  	
    int i = n;
    int desc = 1;
    do {
        for (int j = n; j > i; j--)
            printf("%d ", j);
        for (int j = 0; j < i*2-1; j++)
            printf("%d ", i);
        for (int j = i+1; j <= n; j++) {
            printf("%d", j);
            if (j != n)
                printf(" ");
        }
        printf("\n");
        
        if (desc) {
            i--;
            if (!i) {
                i = 2;
                desc = 0;
            }
        } else
            i++;
    } while (i <= n);

    return 0;
}
