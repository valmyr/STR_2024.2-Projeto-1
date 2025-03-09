#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include<queue>
#include <unistd.h> // For sleep()
using namespace std;
struct Usuario{
    int andarAtual;
    int andarDestino;
    int idUser;
};
queue<Usuario> fila;
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
    return 0;
}
static void *solicitacao(void *arg){
    Usuario user;
    while(true){
        idUser+=1;
        andarDestino = rand()%6;
        do{
            andarAtual =rand()%6;
        }while(andarDestino == andarAtual);
        cout<<"[    Usuario "<< idUser <<"  ] Chamando o elevador do andar  "<< andarCorrente << "  para o andar    "<<andarDestino<<endl;
        sleep(rand()%4);
        user.andarAtual = andarAtual;
        user.andarDestino = andarDestino;
        user.idUser = idUser;
        fila.push(user);
    }
    return nullptr;
}