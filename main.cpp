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


    return 0;
}
