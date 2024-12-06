#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t ret;

    ret = fork();

    if (ret > 0) {
        wait(NULL);
        printf("Parent process done\n");
    } else {
        execl("/bin/echo", "echo", "Hello from the child process", (char*)NULL);

        perror("execl failed"); // If execl() fails
        exit(1);
    }
    return 0;
}