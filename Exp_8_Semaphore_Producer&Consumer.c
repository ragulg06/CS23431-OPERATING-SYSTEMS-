#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define SIZE 3 // Buffer size

int buffer[SIZE];
int in = 0, out = 0, item = 0;
sem_t empty, full, mutex;

// Function to produce an item
void produce() {
    if (sem_trywait(&empty) != 0) {
        printf("Buffer is full!!\n");
        return;
    }

    sem_wait(&mutex);
    item++;
    buffer[in] = item;
    printf("Producer produces the item %d\n", item);
    in = (in + 1) % SIZE;
    sem_post(&mutex);
    sem_post(&full);
}

// Function to consume an item
void consume() {
    if (sem_trywait(&full) != 0) {
        printf("Buffer is empty!!\n");
        return;
    }

    sem_wait(&mutex);
    int consumed_item = buffer[out];
    printf("Consumer consumes item %d\n", consumed_item);
    out = (out + 1) % SIZE;
    sem_post(&mutex);
    sem_post(&empty);
}

int main() {
    int choice;

    // Initialize semaphores
    sem_init(&empty, 0, SIZE);  // All slots are empty
    sem_init(&full, 0, 0);      // No filled slots yet
    sem_init(&mutex, 0, 1);     // Mutex is initially unlocked

    while (1) {
        printf("\n1. Producer\n2. Consumer\n3. Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                produce();
                break;
            case 2:
                consume();
                break;
            case 3:
                printf("Exiting...\n");
                sem_destroy(&empty);
                sem_destroy(&full);
                sem_destroy(&mutex);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
