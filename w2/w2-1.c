#include <stdio.h>
#include <stdlib.h>

void allocArray(int ***p, int m, int n) {
    int **s = calloc(m, sizeof(int *));
    for(int i = 0; i < m; i++) {
        s[i] = calloc(n, sizeof(int));
    }
    *p = s;
}

int main()
{
    int **arr, *a;
    allocArray(&arr, 5, 10);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%p ", &(arr[i][j]));
        }
    }
    return 0;
}
