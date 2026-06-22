#include <stdio.h>
#include <sys/time.h>

double now() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec / 1000000.0;
}

int main() {
    double start = now();

    // meassure
    for (volatile int i = 0; i < 1000000; i++);

    double end = now();
    printf("Time: %f seconds\n", end - start);
}