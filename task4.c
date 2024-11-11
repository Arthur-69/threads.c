#include <pthread.h>
#include <stdio.h>

#define ARRAY_SIZE 5

int array[ARRAY_SIZE] = {1, 2, 3, 4, 5};

void* calculate_square(void* arg) {
    long num = (long)arg;
    printf("Square of %ld is %ld\n", num, num * num);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_create(&threads[i], NULL, calculate_square, (void*)(long)array[i]);
    }
    for (int i = 0; i < ARRAY_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Square calculation completed.\n");
    return 0;
}