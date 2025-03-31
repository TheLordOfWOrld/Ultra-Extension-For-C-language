#include <stdio.h>
#include <stdlib.h>
#include "Algorithm/sort.h"

int compare_int(const void *a, const void *b) {
    return *(const int*)a - *(const int*)b;
}

int main() {
    // 普通数组排序
    int static_arr[] = {5, 2, 9, 1, 5};
    SORT_ARRAY(static_arr, compare_int);
    
    printf("Static array sorted: ");
    for (size_t i = 0; i < sizeof(static_arr)/sizeof(static_arr[0]); i++) {
        printf("%d ", static_arr[i]);
    }
    printf("\n");

    // 动态数组排序
    size_t dynamic_size = 6;
    int *dynamic_arr = malloc(dynamic_size * sizeof(int));
    for (size_t i = 0; i < dynamic_size; i++) {
        dynamic_arr[i] = 10 - i;
    }

    quicksort(dynamic_arr, dynamic_size, sizeof(int), compare_int);

    printf("Dynamic array sorted: ");
    for (size_t i = 0; i < dynamic_size; i++) {
        printf("%d ", dynamic_arr[i]);
    }
    printf("\n");

    free(dynamic_arr);
    return 0;
}