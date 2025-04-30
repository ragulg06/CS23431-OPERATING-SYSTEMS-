#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid;

    pid = fork()

    if(pid==-1){
        printf("CHILD PROCESS NOT CREATED\n");
        exit(0);
    }else if(pid == 0){
        printf("CHILD PROCESS CREATED \n");
        printf("CHILD PROCESS ID: %d\n", getpid());
        printf("PARENT PROCESS ID: %d\n". getppid());
    }else{
        printf("PARENT PROCESS CREATED \n");
        printf("PARENT PROCESS ID: %d\n", getpid());
        printf("CHILD PROCESS ID: %d\n", pid);
    }
    return 0;
}