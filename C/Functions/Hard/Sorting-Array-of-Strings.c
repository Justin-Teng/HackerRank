#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int distinct_helper(const char* s) {
    int dist = 0;
    while (*s != '\0') {
        if (!strchr(s+1, *s))
            dist++;
        s++;
    }
    return dist;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int diff = distinct_helper(a) - distinct_helper(b);
    if (diff != 0)
        return diff;
    return lexicographic_sort(a, b);
}

int sort_by_length(const char* a, const char* b) {
    if (strlen(a)-strlen(b) != 0)
        return strlen(a)-strlen(b);
    return lexicographic_sort(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    // Insertion sort
    for (int i = 1; i < len; ++i) {
        char* key = arr[i];
        int j = i-1;
        while (j >= 0 && cmp_func(arr[j], key) > 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
