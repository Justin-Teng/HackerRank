#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    const char* sa = *(const char**) a;
    const char* sb = *(const char**) b;
    return strcmp(sa, sb);
}

int next_permutation(int n, char **s) {
	char** sorted = (char**) malloc(n*sizeof(char*));
    for (int i = 0; i < n; i++) {
        sorted[i] = (char*) malloc(11 * sizeof(char));
        strcpy(sorted[i], s[i]);
    }
    
    qsort(sorted, n, sizeof(char*), cmp);

    int* positions = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        const char* str = s[i];
        for (int j = 0; j < n; ++j) {
            if (strcmp(str, sorted[j]) == 0) {
                positions[i] = j;
                break;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        free(sorted[i]);
    }
    
    for (int i = n-2; i >= 0; --i) {
        int x = positions[i];
        for (int j = n-1; j > i; --j) {
            if (positions[j] > x) {
                char* temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                int count = 0;
                for (int k = 1; k < n; ++k) {
                    char* temp = s[i+k];
                    s[i+k] = s[n-k];
                    s[n-k] = temp;
                    if (++count >= (n-i)/2)
                        break;
                }
                free(positions);
                return 1;
            }
        }
    }
    free(positions);
    return 0;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
