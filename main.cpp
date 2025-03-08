#include <iostream>
#include <pthread.h>
#include <queue>
#include <semaphore.h>
#include <unistd.h> // For sleep()

sem_t semaphore; // Semaphore
int count = 0;

void* producer(void* arg) {
    while (true) {
        sleep(1); // Simulate work
        count++;
        std::cout << "Producer: Producing item. It has "<< count << " itens\n";
        sem_post(&semaphore); // Release (increment) semaphore
    }
    return nullptr;
}

void* consumer(void* arg) {
    while (true) {
        sem_wait(&semaphore); // Wait (decrement) semaphore
        count--;
        std::cout << "Consumer: Consuming item. It has "<< count << " itens\n";
        sleep(1); // Simulate work
    }
    return nullptr;
}

int main() {
    pthread_t producerThread, consumerThread;

    // Initialize semaphore with value 0
    sem_init(&semaphore, 0, 0);

    // Create threads
    pthread_create(&producerThread, nullptr, producer, nullptr);
    pthread_create(&consumerThread, nullptr, consumer, nullptr);

    // Join threads (infinite loop, will run forever)
    pthread_join(producerThread, nullptr);
    pthread_join(consumerThread, nullptr);

    // Destroy semaphore (not reached in this example)
    sem_destroy(&semaphore);

    return 0;
}
