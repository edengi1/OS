#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


int main() {

    printf("Main PID is %d\n", getpid());

    
    char *args[] = {NULL};


    pid_t p1 = fork();
    pid_t p2,p3;

    if (p1 == 0) {
        // Child process
        printf("\nTask: 1 , PID = %d\n", getpid());
        execv("./main2_1", args);
        // exit(1);
    } else {
        // Back to main process

        p2 = fork();

        if(p2 == 0) {
            // Another child process
            printf("\nTask: 3 , PID = %d\n", getpid());
            execv("./main2_3", args);
            // exit(1);

        } else {
            p3 = fork();

            if(p3 == 0) {
                printf("\nTask: 2 , PID = %d\n", getpid());
                execv("./main2_2", args);

                // exit(1);
                
            }
        }
    }

    

    printf("Wait for processes: ...\n");

    waitpid(p1, 0, WUNTRACED);
    waitpid(p3, 0, WUNTRACED); 
    // waitpid(p2, 0, WUNTRACED); // main2_3 process will not die untill daemon is finished.
    
    return 0;
}
