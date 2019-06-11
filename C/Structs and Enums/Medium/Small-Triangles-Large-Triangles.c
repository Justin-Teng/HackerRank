#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

int cmp(const void* a, const void* b) {
    const triangle* ta = (const triangle*) a;
    const triangle* tb = (const triangle*) b;
    
    double pa = (ta->a + ta->b + ta->c) / 2.0;
    double va = sqrt(pa * (pa - ta->a) * (pa - ta->b) * (pa - ta->c));
    
    double pb = (tb->a + tb->b + tb->c) / 2.0;
    double vb = sqrt(pb * (pb - tb->a) * (pb - tb->b) * (pb - tb->c));
    
    if (va - vb > 0)
        return 1;
    return -1;
}

void sort_by_area(triangle* tr, int n) {
	qsort(tr, n, sizeof(triangle), cmp);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
