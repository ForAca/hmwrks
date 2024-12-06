#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){
    pid_t ret1, ret2;

    ret1 = fork();

    if (ret1 > 0) {
        wait(NULL);

        ret2 = fork();
        if (ret2 > 0) {
            wait(NULL);

            waitpid(ret2, NULL, 0);
            printf("Parent process done\n");
        } else {
            waitpid(ret1, NULL, 0);
            execl("/bin/date", "date", "+%Y-%m-%d", (char *)NULL);

            perror("execl failed");
            exit(1);
        }
    } else {
        execl("/bin/ls", "ls", ".", (char*)NULL);

        perror("execl failed");
        exit(1);
    }
    
    return 0;
}