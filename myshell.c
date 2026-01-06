#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    char line[1024];

    while ( 1 ) {

        printf("myshell> ");
        fflush(stdout);


        if ( fgets( line, sizeof(line), stdin) == NULL ) {
            break;
        } 

        line[strcspn(line, "\n")] =0;

        if ( stringcmp(line, "exit") == 0 ) {
            break;
        }

        pid_t pid = fork();

        if ( pid < 0 ) {
            perror("fork");
            continue;
        }

        if ( pid == 0 ) {

            char *args[] = {line, NULL}
            execvp(args[0], args);

            perror("exitvp");
            exit(1);
        }   else {

            wait(NULL);
        }
    }

    return 0;
}