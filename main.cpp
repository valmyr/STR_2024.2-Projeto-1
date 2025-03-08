#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include<queue>
#include <unistd.h> // For sleep()
using namespace std;
sem_t semaphore; // Semaphore
int count = 0;

// void* producer(void* arg) {
//     while (true) {
//         sleep(1); // Simulate work
//         count++;
//         std::cout << "Producer: Producing item. It has "<< count << " itens\n";
//         sem_post(&semaphore); // Release (increment) semaphore
//     }
//     return nullptr;
// }

// void* consumer(void* arg) {
//     while (true) {
//         sem_wait(&semaphore); // Wait (decrement) semaphore
//         count--;
//         std::cout << "Consumer: Consuming item. It has "<< count << " itens\n";
//         sleep(1); // Simulate work
//     }
//     return nullptr;
// }
struct Usuario{
    int andar_atual;
    int andar_alvo;
};

class Elevador{
    public:
        int andar_corrente;
        int idUser;
        void solicitacao(int,int);
    private:
        pthread_t Requisicao;
        void mover_para_solictacao();
        void mover_para_destino();
    Elevador();
    ~Elevador();
};
Elevador::Elevador(){andar_corrente = 0; idUser = 0;}
Elevador::~Elevador(){}
void Elevador::solicitacao(int andarAtual, int andarDestino){
    idUser+=1;
    cout<<"[Usuario "<< idUser <<" ] chamando o elevador do andar"<< andar_corrente << "para o andar"<<andarDestino<<endl;

}

int main() {
    pthread_t RequestThread, Move_solThread, Move_deliveThread;

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
