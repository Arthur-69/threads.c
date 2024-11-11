#include <pthread.h>
#include <stdio.h>

void* print_numbers(void* arg) {
    long thread_id = (long)arg;
    for (int i = 1; i <= 5; i++) {
        printf("Thread %ld prints %d\n", thread_id, i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, print_numbers, (void*)i);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads completed.\n");
    return 0;
}