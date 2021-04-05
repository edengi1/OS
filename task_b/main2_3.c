#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    printf("----------------- TASK 3  (%d)-----------------\n", getpid());
    // 1. Create a child process by forking from the parent process.
    pid_t pid = fork(); 

    if(pid == 0) {
        
        // Child --> Want to make a daemon process out of it.
        
        //Init Daemon: 
        // 2. "Move" process to root directory ('/'). 'change directory'
        chdir("/");

        // 3. Change session of the daemon process, so the parent proc and daemon child proc 
        // will not be connected.
        // If Child cannot die so parent cannot die also.
        setsid();

        printf("Daemon started!\n");
        // 4. Close all I/O chanlles (stdin, stdout, stderr)
        close(stdin);
        close(stdout);
        close(stderr);

        openlog("MyDaemonLog",LOG_PID,LOG_DAEMON);
        syslog(LOG_NOTICE,"daemon stating..\n");
        sleep(3);
        syslog(LOG_NOTICE,"daemon doing some work..\n");
        sleep(3);
        syslog(LOG_NOTICE,"daemon finished..\n");

        sleep(10);
        printf("Daemon finished working!\n");

    } else {
        // Parent
        printf("daemon pid: %d\n",pid);
        exit(1);
    }

    return 1;
}
