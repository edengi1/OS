#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define STACK_SIZE 10000

int foo(char *str, int pid) {
    
    for(int i = 0; i < 10; i++) {
        printf("Hello from %s, PID = %d\n", str, pid);
        sleep(1);
    }
    
    // exit(1);
    return 1;
}

int handler() {
    // sleep(5);
    foo("Task 2", getpid());
    printf("???????????????????????");
    return 1;
}

int main() {

    printf("----------------- TASK 2 -----------------\n");
    char stack[STACK_SIZE + 1];
    
    int proc1 = clone(handler, stack + STACK_SIZE, CLONE_PARENT, 0);
    int proc2 = clone(handler, stack + STACK_SIZE, CLONE_PARENT, 0);
    
    foo("Task 2 MAIN", getpid());


    printf("pid1: %d\npid2: %d\n", proc1, proc2);

    printf("Task 2 finished!\n");
    

    return 0;
}