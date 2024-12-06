#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>  // For execl()
#include <unistd.h>

int main(){
    int ret;

    ret = fork();

    if (ret > 0) {
        printf("Parent process done\n");
    } else {
        execl("/bin/ls", "ls", ".", (char*)NULL);

        perror("execl failed"); // If execl() fails
        exit(1);
    }
    return 0;
}