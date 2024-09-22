#include <stdio.h>
#include <pthread.h>

int count = 0;

void *increment(void *arg) {
    for (int i = 0; i < 100000; i++) {
        count++;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final count: %d\n", count);

    return 0;
}
