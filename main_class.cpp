#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include<queue>
#include <unistd.h> // For sleep()
using namespace std;
struct Usuario{
    int andar_atual;
    int andar_alvo;
};

class Elevador{
    public:
        int andar_corrente;
        int idUser;
        int andarAtual;
        int andarDestino;
        int andarCorrente;
        void* solicitacao(void *arg);
        Elevador();
        ~Elevador();
    private:
        void mover_para_solictacao();
        void mover_para_destino();

};
Elevador::Elevador(){andar_corrente = 0; idUser = 0;}
Elevador::~Elevador(){}
void* Elevador::solicitacao(void *arg){
    while(true){
        idUser+=1;
        andarDestino = rand()%6;
        do{
            andarAtual =rand()%6;
        }while(andarDestino == andarAtual);
        cout<<"[Usuario "<< idUser <<" ] chamando o elevador do andar "<< andarCorrente << " para o andar "<<andarDestino<<endl;
    }
    return ;
}


int main() {
    srand(time(NULL));
    Elevador Elenv;
    pthread_t soliciatcaoThread;
    void *p;
    Elenv.solicitacao()

    
    pthread_create(&soliciatcaoThread, nullptr,, nullptr);
    //return 0;
}
