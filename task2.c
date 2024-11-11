#include <pthread.h>
#include <stdio.h>

#define ARRAY_SIZE 6

int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6};

typedef struct {
    int start;
    int end;
} ArrayRange;

void* calculate_partial_sum(void* arg) {
    ArrayRange* range = (ArrayRange*)arg;
    int sum = 0;
    for (int i = range->start; i < range->end; i++) {
        sum += array[i];
    }
    printf("Partial sum from index %d to %d is %d\n", range->start, range->end - 1, sum);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    ArrayRange ranges[2] = {{0, ARRAY_SIZE / 2}, {ARRAY_SIZE / 2, ARRAY_SIZE}};

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, calculate_partial_sum, &ranges[i]);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Array processing completed.\n");
    return 0;
}