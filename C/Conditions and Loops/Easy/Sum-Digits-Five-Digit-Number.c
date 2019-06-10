#include <stdio.h>

int main() {
	
    int n;
    scanf("%d", &n);
    int sumdigits = 0;
    while (n) {
        sumdigits += n % 10;
        n /= 10;
    }
    printf("%d", sumdigits);
    return 0;
}
