#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore..h>
#include <unistd.h>

#define SIZE 5 

int buffer[SIZE];
int in = 0, out = 0, item = 1;

semt_t empty;
sem_t full;
sem_t mutex;

void* producer(void* arg){
    for(int i=0; i<10;i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Producer Produces item %d at buffer [%d]\n", item, in);
        in = (int + 1) %SIZE;
        item++;

        sem_post(&mutex);
        sem_post(&full);
        sleep(i);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg){
    for(int i=0; i< 10; i++){
        sem_wait(&full);
        sem_wait(&mutex);

        int x = buffer[out];
        printf("Consumer consumes item %d from buffer [%d]\n", x, out);
        out = (out + 1) % SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t prod_thread, cons_thread;
    sem_init(&empty, o, SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;

}