#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
// main process:

void foo(const char *pid) {

    for(int i = 0; i < 10; i++) {
        printf("Hello from %s, my PID is: %d\n", pid, getpid());
        sleep(1);
    }
}


int main() {

    printf("----------------- TASK 1 -----------------\n");

    pid_t pid = fork(); //Split into 2 Threads, Main -> Child

    if(pid == 0) {
        // We're inside child process

        pid = fork(); // Split into 3 Threads: Main -> Child --> GrandChild
        

        if(pid == 0) {
            // We're inside grandchild 
            
            foo("Task 1 Grandchild");
            // exit(1);
            return 0;
        } else if(pid > 0){
            foo("Task 1 Child");
        }

    } else if(pid > 0){
        // We're inside parent process

        foo("Task 1 APP");
        printf("Main App %d\n", getpid());
        printf("----------- Task 1 finished! ------------\n");
        // exit(1);
    }

    
    

    // exit(1);
    return 0;
}