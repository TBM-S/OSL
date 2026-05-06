#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t r1, r2;

void* t1(void* arg) {
    printf("Thread 1: Locking R1...\n"); pthread_mutex_lock(&r1);
    printf("Thread 1: Locked R1. Locking R2...\n"); sleep(1);
    pthread_mutex_lock(&r2);
    printf("Thread 1: Locked R2. Releasing...\n");
    pthread_mutex_unlock(&r2); pthread_mutex_unlock(&r1);
    return NULL;
}

void* t2(void* arg) {
    printf("Thread 2: Locking R2...\n"); pthread_mutex_lock(&r2);
    printf("Thread 2: Locked R2. Locking R1...\n"); sleep(1);
    pthread_mutex_lock(&r1);
    printf("Thread 2: Locked R1. Releasing...\n");
    pthread_mutex_unlock(&r1); pthread_mutex_unlock(&r2);
    return NULL;
}

int main() {
    pthread_t th1, th2;
    pthread_mutex_init(&r1, NULL);
    pthread_mutex_init(&r2, NULL);

    printf("===== Deadlock Demonstration =====\n");
    pthread_create(&th1, NULL, t1, NULL);
    pthread_create(&th2, NULL, t2, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    pthread_mutex_destroy(&r1);
    pthread_mutex_destroy(&r2);
    return 0;
}
