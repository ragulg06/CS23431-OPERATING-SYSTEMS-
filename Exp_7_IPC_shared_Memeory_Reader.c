#include <sys/types.h>
#include <sys/ipc.h>
#include <sys.shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SharedMemSize 50

int main(){
    int shmid;
    key_t key = 5677;
    char *shared_memory;

    if((shmid = shmget(key, SharedMemSize, 0666))<0){
        perror("shmget failed");
        exit(1);
    }

    if((shared_memory = shmat(shmid, NULL, 0)) == (char*)-1){
        perror("shmat failed");
        exit(1);
    }
    printf("Reader: Message received: %s\n", shared_memory);
    return 0;
}