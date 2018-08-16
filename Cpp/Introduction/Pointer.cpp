#include <stdio.h>
#include <iostream>

void update(int *a,int *b) {
    int tempA = *a;
    int tempB = *b;
    int tempC = tempA+tempB;
    *a = tempC;
    int tempD = tempA-tempB;
    if (tempD < 0)
        tempD = tempD * -1;
    *b = tempD;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
