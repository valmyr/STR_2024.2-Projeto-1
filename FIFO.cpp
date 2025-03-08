#include <iostream>
#include <queue>
#include <chrono>
#include <thread> 

using namespace std;

int main() {
    queue<int> fifoQueue; // Fila FIFO de inteiros
    int inputValue, option;

    while (true) {
        cout << "1 - Solicita" << endl;
        cout << "2 - Movimenta" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha: ";
        cin >> option;

        switch (option) {
            case 1: // Adicionar elemento à fila
                cout << "Insira o Andar Desejado: ";
                cin >> inputValue;
                fifoQueue.push(inputValue);
                cout << "Elemento " << inputValue << " adicionado a fila!" << endl;
                this_thread::sleep_for(chrono::seconds(2));  // Pausa por 2 segundos
                system("clear||cls"); 
                break;

            case 2: // Remover elemento da fila
                if (!fifoQueue.empty()) {
                    cout << "O elevador chegou ao andar: " << fifoQueue.front() << endl;
                    fifoQueue.pop(); // Remove o primeiro elemento da fila
                    this_thread::sleep_for(chrono::seconds(2)); 
                } else {
                    cout << "Fila vazia! Sem elementos para remover." << endl;
                    this_thread::sleep_for(chrono::seconds(1));  
                }
                system("clear||cls"); 
                break;

            case 3: // Sair
                cout << "Saindo do programa..." << endl;
                system("clear||cls");  
                return 0;  

            default:
                cout << "Escolha inexistente! Tente novamente." << endl;
            
                break;
        }
    }

    return 0;
}
