# Controle de Elevador Simplificado

Neste projeto, vamos desenvolver um simulador de elevador concorrente utilizando linguagem C e semáforos no Linux. O sistema contará com um único elevador que atende múltiplos usuários concorrentes em um prédio de 5 andares. O objetivo é gerenciar chamadas de forma organizada, garantindo que o elevador atenda os usuários corretamente sem conflitos entre threads.

## Ferramentas e suas versões
 * `Ubuntu 20.04.02` 
 * `g++ 9.4.0`
 * `C++ 17`
  

## Bibliotecas utilizadas
  * **iostream**: Parte da biblioteca input/output, sendo responsável pelas entradas e saídas do programa.
    * Principais funções: `cout` e `cin`;
  * **pthread.h**: Contém declarações de função e mapeamentos para interfaces de threading. O cabeçalho inclui o cabeçalho sched.h.
    * Principais funções: `pthread_create`, `pthread_join`;
  * **semaphore.h**: Fornece funções para manipulação de semaforos em sistemas baseados em Unix/Linux, permitindo a sincronização de processos e threads.
    * Principais funções: `sem_wait`, `sem_post`;
  * **queue**: Fornece e facilita implementações de estruturas de dados do tipo fila.
    * Principais funções: `push`, `pop` e `front`;
  * **unistd.h**: Permite acessar a API do sistema operacional POSIX.
    * Principais funções: `sleep`, `close`;

## Clonando um Repositório Git

Para copiar esse repositório remoto na sua máquina local, utilize o comando `git clone` com o HTTPS do repositório.

```
git clone https://github.com/valmyr/STR_2024.2-Projeto-1.git
```

Em seguida, para compilar o código em sua máquina acesse o diretório onde você executou o git clone e execute o seguinte comando no terminal: \
``` g++ -pthread -lpthread -lrt -o main.o main.cpp ```

## Vídeo
link
