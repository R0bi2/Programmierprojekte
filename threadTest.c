#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *mythread(void *args) {
    int *var = (int *) args;

    printf("Hallo vom Thread\n");

    *var = *var + 3;

    printf("Hey ich habe var aufgestockt: %d\n", *var);

    return NULL;
}

int main() {
    pthread_t p;

    int *var = malloc(sizeof(int));
    *var = 7;

    pthread_create(&p, NULL, mythread, var);

    printf("Hallo von der main vor join (var: %d)\n", *var);

    pthread_join(p, NULL);

    printf("Hallo von der main nach join (var: %d)\n", *var);

    free(var);
    return 0;
}