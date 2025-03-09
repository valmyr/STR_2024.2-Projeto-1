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
static void *buscaUsuario(void *arg);
void mover_para_solictacao();
void mover_para_destino();



int main() {
    srand(time(NULL));
    pthread_t soliciatcaoThread, elevadorThread;
    pthread_create(&soliciatcaoThread, nullptr,solicitacao, nullptr);
    pthread_create(&elevadorThread, nullptr, buscaUsuario, nullptr);
    pthread_join(soliciatcaoThread, nullptr);
    pthread_join(elevadorThread, nullptr);
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
        cout<<"[Usuario "<< idUser <<"] Chamando o elevador do andar  "<< andarAtual << "  para o andar    "<<andarDestino<<endl;

        sleep(rand()%4+4);
        user.andarAtual = andarAtual;
        user.andarDestino = andarDestino;
        user.idUser = idUser;
        
        fila.push(user);
        
        cout<< fila.size()<<endl;
    }
    return nullptr;
}

static void *buscaUsuario(void *arg){
    Usuario user;
    while(true){
        if(fila.size() > 0)
        {
            user = fila.front();

        cout<<endl<<"[Elevador]" <<" Nova chamada recebida de Usuário  "<< user.idUser << ":  Andar  "<<user.andarAtual<<" -> "<<user.andarDestino<<"."<<endl;
        sleep(1);
        cout<<"[Elevador] Movendo-se para o andar "<<user.andarAtual<<"..."<<endl;
        andarCorrente = user.andarAtual;
        sleep(1);
        cout<<"[Elevador] Chegou ao andar "<<andarCorrente<<". Usuário "<<user.idUser<<" embarcou."<<endl;
        sleep(1);
        int distanciaRelativa = user.andarAtual-user.andarDestino > 0 ? user.andarAtual-user.andarDestino:-(user.andarAtual-user.andarDestino);

        for(int i=0; i < distanciaRelativa; i++){
            (andarCorrente > user.andarDestino) ?  andarCorrente-- :  andarCorrente++;
            cout<<"[Elevador] Movendo-se para o andar "<<andarCorrente<<"..."<<endl;
            sleep(1);
        }

        cout<<"[Elevador] Chegou ao andar "<<andarCorrente<<". Usuário "<<user.idUser<<" desembarcou."<<endl;
        sleep(1);
        fila.pop();
        }
        
    }
    return nullptr;
}