#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* print_thread_message(void* arg) {
    long thread_id = (long)arg;
    printf("Thread %ld is running\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];
    for (long i = 0; i < 3; i++) {
        if (pthread_create(&threads[i], NULL, print_thread_message, (void*)i)) {
            fprintf(stderr, "Error creating thread %ld\n", i);
            return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads completed.\n");
    return 0;
}