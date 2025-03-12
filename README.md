# Equipe: 

Arthur Henrique Rocha Alves     - 119211079\
José Andrew Pessoa De Oliveira  - 118210339\
Valmir Ferreira da Silva        - 119211110
        
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
    * Principais funções: `pthread_create` e `pthread_join`;
  * **semaphore.h**: Fornece funções para manipulação de semaforos em sistemas baseados em Unix/Linux, permitindo a sincronização de processos e threads.
    * Principais funções: `sem_wait` e `sem_post`;
  * **queue**: Fornece e facilita implementações de estruturas de dados do tipo fila.
    * Principais funções: `push`, `pop` e `front`;
  * **unistd.h**: Permite acessar a API do sistema operacional POSIX.
    * Principais funções: `sleep` e `close`;

## Clonando um Repositório Git

Para copiar esse repositório remoto na sua máquina local, utilize o comando `git clone` com o HTTPS do repositório.

```
git clone https://github.com/valmyr/STR_2024.2-Projeto-1.git
```

Em seguida, para compilar o código em sua máquina acesse o diretório onde você executou o git clone e execute o seguinte comando no terminal: 
```
g++ -pthread -o main.o main.cpp
```
ou
```
bash run.sh
```

## Funcionamento do Sistema

<p align="justify"> O sistema simula o funcionamento de um elevador com múltiplos usuários fazendo solicitações em diferentes andares. Existem duas threads principais no programa: uma para gerar as solicitações dos usuários e outra para atender essas solicitações. A thread responsável pelas solicitações cria usuários com andares de origem e destino aleatórios, adicionando suas informações a uma fila. A cada ciclo, um novo usuário é criado, e sua solicitação é enfileirada após um tempo aleatório. O semáforo é utilizado para sincronizar o processo, garantindo que a 
thread que simula o elevador (responsável por atender as solicitações) só processe a próxima solicitação quando o semáforo for sinalizado. </p>

<p align="justify">  A outra thread, a que simula o elevador, aguarda até que haja uma solicitação na fila, o que é indicado pelo semáforo. Quando o semáforo é sinalizado, o elevador pega a primeira solicitação da fila e começa a simular o movimento até o andar de origem do usuário. Depois disso,ele recebe o usuário e se move até o seu destino, com o movimento entre os andares sendo simulado através de um laço que aumenta ou diminui o andar atual do elevador, dependendo da direção do movimento.</p>

<p align="justify"> Cada movimentação do elevador entre andares é exibida, mostrando ao usuário o andamento da viagem, com o elevador se movendo de um andar a outro até chegar ao destino. Após o desembarque do usuário, a solicitação é removida da fila, e o elevador 
retorna ao estado de espera para atender a próxima solicitação. Esse processo continua indefinidamente, simulando o comportamento de um sistema de multitarefas onde várias solicitações podem ser feitas ao mesmo tempo e são atendidas conforme a ordem de 
chegada. </p>

## Código de Cores

<p align="center">
  <img src=https://github.com/valmyr/STR_2024.2-Projeto-1/blob/main/Img/OutputSTR24_2.png alt="Saída do programa."/>
</p>

🔵 Azul: Solicitação do usuário. \
⚪ Branco: Elevador se deslocando até o usuário embarcar. \
🔴 Vermelho: Elevador em movimento do andar de embarque ao destino. \
🟢 Verde: Usuário desembarcando.

## Vídeo
link
