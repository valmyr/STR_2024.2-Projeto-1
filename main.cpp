#include <iostream>
#include <pthread.h>
#include <queue>
#include <semaphore.h>
#include<queue>
#include <unistd.h> // For sleep()
using namespace std;


int andarAtual;
int andarDestino;
static int andarCorrente = 0;
static int idUser = 0;
static void *solicitacao(void *arg);
void mover_para_solictacao();
void mover_para_destino();

int main() {
    srand(time(NULL));
    pthread_t soliciatcaoThread;
    pthread_create(&soliciatcaoThread, nullptr,solicitacao, nullptr);
    pthread_join(soliciatcaoThread, nullptr);
    //return 0;
}
static void *solicitacao(void *arg){
    while(true){
        idUser+=1;
        andarDestino = rand()%6;
        do{
            andarAtual =rand()%6;
        }while(andarDestino == andarAtual);
        cout<<"[Usuario "<< idUser <<" ] chamando o elevador do andar "<< andarCorrente << " para o andar "<<andarDestino<<endl;

    }
    return nullptr;
}