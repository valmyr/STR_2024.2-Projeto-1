#include <iostream>  
#include <stdlib.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <queue>     
#include <unistd.h>  

using namespace std;

// Definindo a estrutura de um usuário
struct Usuario {
    int andarAtual;   // Andar atual do usuário
    int andarDestino; // Andar de destino do usuário
    int idUser;       // ID do usuário
};

// Fila que irá armazenar as solicitações de usuários
queue<Usuario> fila;

// Semáforo para sincronizar o processo de atendimento das solicitações
sem_t semaphore;

// Variáveis globais
int andarAtual;                // Andar atual do elevador
int andarDestino;              // Andar de destino do elevador
static int andarCorrente = 0;  // Andar atual do elevador
static int idUser = 0;         // ID do próximo usuário

// Funções que representam as threads
static void *solicitacao(void *arg);
static void *buscaUsuario(void *arg);

int main() {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));  

    // Declaração das threads
    pthread_t soliciatcaoThread, elevadorThread;  

    // Inicializa o semáforo com valor 0 (bloqueando inicialmente)
    sem_init(&semaphore, 0, 0);  
    
    // Criação das threads para solicitar elevador e para o elevador buscar usuários
    pthread_create(&soliciatcaoThread, nullptr, solicitacao, nullptr);
    pthread_create(&elevadorThread, nullptr, buscaUsuario, nullptr);
    
    // Espera as threads terminarem sua execução
    pthread_join(soliciatcaoThread, nullptr);
    pthread_join(elevadorThread, nullptr);
    
    // Destrói o semáforo após o uso
    sem_destroy(&semaphore);
    return 0;
}

// Função que simula a solicitação de elevador por usuários
static void *solicitacao(void *arg) {
    Usuario user;  // Criação de uma variável do tipo Usuario para armazenar a solicitação
    
    while(true) {
        // Incrementa o ID do usuário a cada nova solicitação
        idUser += 1; 
        // Gera aleatoriamente o andar de destino (de 0 a 5)
        andarDestino = rand() % 6;  
        
        // Garante que o andar de destino é diferente do andar atual
        do {
            andarAtual = rand() % 6; 
        } while(andarDestino == andarAtual);

        // Exibe a mensagem de solicitação
        cout << "\033[0m\033[33;44m[Usuario " << idUser << "] Chamando o elevador do andar " 
             << andarAtual << " para o andar " << andarDestino << "\033[0m" << endl;
        
        // Espera aleatoriamente entre 0 a 9 segundos antes de fazer a próxima solicitação
        sleep(rand() % 10); 
        
        // Preenche a estrutura 'user' com os dados da solicitação
        user.andarAtual = andarAtual;
        user.andarDestino = andarDestino;
        user.idUser = idUser;
        
        // Coloca o usuário na fila de solicitações
        fila.push(user);
        
        // Sinaliza o semáforo para a thread do elevador começar a atender a solicitação
        sem_post(&semaphore);
    }
    return nullptr;
}

// Função que simula o movimento do elevador e o atendimento aos usuários
static void *buscaUsuario(void *arg) {
    Usuario user;  
    
    while(true) {
        // Espera até que uma solicitação esteja na fila
        sem_wait(&semaphore);

        // Pega o primeiro usuário da fila
        user = fila.front();
        
        // Exibe a mensagem de atendimento ao usuário
        cout << "[Elevador] Nova chamada recebida de Usuário " << user.idUser 
             << ": Andar " << user.andarAtual << " -> " << user.andarDestino << "." << endl;
        
        sleep(1);  // Aguarda um tempo antes de movimentar o elevador
        
        // Exibe que o elevador está se movendo para o andar do usuário
        cout << "[Elevador] Movendo-se para o andar " << user.andarAtual << "..." << endl;
        
        // Atualiza o andar atual do elevador para o andar de solicitação do usuário
        andarCorrente = user.andarAtual;
        sleep(1);  // Aguarda o elevador chegar ao andar
        
        // Exibe que o elevador chegou ao andar do usuário
        cout << "[Elevador] Chegou ao andar " << andarCorrente << ". Usuário " << user.idUser 
             << " embarcou." << endl;
        
        sleep(1);  

        // Calcula a distância relativa entre o andar atual e o andar de destino
        int distanciaRelativa = user.andarAtual - user.andarDestino > 0 ? 
                                user.andarAtual - user.andarDestino : -(user.andarAtual - user.andarDestino);

        // Move o elevador para o andar de destino do usuário
        for(int i = 0; i < distanciaRelativa; i++) {
            // Move o elevador para cima ou para baixo dependendo da direção
            (andarCorrente > user.andarDestino) ? andarCorrente-- : andarCorrente++;
            cout << "\033[0m\033[31m" << "[Elevador] Movendo-se para o andar " << andarCorrente << "...\033[0m" << endl;
            sleep(1);  // Aguarda o tempo de movimento entre andares
        }

        // Exibe que o elevador chegou ao andar de destino e o usuário desembarcou
        cout << "\033[0m\033[32m" << "[Elevador] Chegou ao andar " << andarCorrente << ". Usuário " 
             << user.idUser << " desembarcou.\033[0m" << endl;
        
        sleep(1);  // Aguarda um tempo antes de finalizar o atendimento ao usuário
        
        // Remove o usuário da fila após ele ser atendido
        fila.pop();
    }
    return nullptr;
}
