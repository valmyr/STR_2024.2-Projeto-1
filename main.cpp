#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include<semaphore.h>


class Semaforo {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int contador;

public:
    Semaforo(int valor) : contador(valor) {}

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return contador > 0; });
        contador--;
    }

    void release() {
        std::unique_lock<std::mutex> lock(mtx);
        contador++;
        cv.notify_one();
    }
};

Semaforo semaforo(2); // Permite até 2 threads simultâneas
using namespace std;

int main(){

    return 0;
}
