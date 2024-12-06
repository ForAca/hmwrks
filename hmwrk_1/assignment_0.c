#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int ret1;

    ret1 = fork();


    if (ret1 > 0) {
        printf("Hello from parent process->%i PID: %d parent PID: %d\n", ret1, getpid(), getppid());
    } else {
        printf("Hello from child process->%i PID: %d parent PID: %d\n", ret1, getpid(), getppid());
    }
    int ret2;

    ret2 = fork();
    

    if (ret2 > 0) {
        printf("Hello from parent process->%i PID: %d parent PID: %d\n", ret2, getpid(), getppid());
    } else {
        printf("Hello from child process->%i PID: %d parent PID: %d\n", ret2, getpid(), getppid());
    }
    int ret3;
    
    ret3 = fork();


    if (ret3 > 0) {
        printf("Hello from parent process->%i PID: %d parent PID: %d\n", ret3, getpid(), getppid());
    } else {
        printf("Hello from child process->%i PID: %d parent PID: %d\n", ret3, getpid(), getppid());
    }

    sleep(1);
    
    return 0;
}