#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *args) {
    printf("Thread gestartet, versucht Lock zu bekommen\n");
    fflush(stdout);

    pthread_mutex_lock(&lock);

    printf("Thread hat Lock bekommen\n");
    fflush(stdout);

    while (1)
        ;

    pthread_mutex_unlock(&lock); // wird nie erreicht
    return NULL;
}

int main() {
    pthread_t A;
    pthread_t B;

    printf("Main: Threads werden erstellt\n");
    fflush(stdout);

    pthread_create(&A, NULL, mythread, NULL);
    pthread_create(&B, NULL, mythread, NULL);

    printf("Main: wartet auf Threads\n");
    fflush(stdout);

    pthread_join(A, NULL);
    pthread_join(B, NULL);

    return 0;
}