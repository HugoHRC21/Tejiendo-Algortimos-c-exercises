#include <iostream>
#include <stdexcept>  
using namespace std;


template <typename T>
class Pila {
private:
    T* datos;
    int capacidad;
    int cima;

    void redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        T* nuevoArreglo = new T[nuevaCapacidad];

        for (int i = 0; i <= cima; ++i) {
            nuevoArreglo[i] = datos[i];
        }

        delete[] datos;
        datos = nuevoArreglo;
        capacidad = nuevaCapacidad;
    }

public:
    Pila() {
        capacidad = 10;
        datos = new T[capacidad];
        cima = -1;
    }

    ~Pila() {
        delete[] datos;
    }

    void push(const T& elemento) {
        if (cima + 1 == capacidad) {
            redimensionar();
        }
        datos[++cima] = elemento;
    }

    void pop() {
        if (isEmpty()) {
            throw runtime_error("La pila está vacía. No se puede hacer pop.");
        }
        --cima;
    }

    T top() const {
        if (isEmpty()) {
            throw runtime_error("La pila está vacía. No hay elemento en el tope.");
        }
        return datos[cima];
    }

    bool isEmpty() const {
        return cima == -1;
    }

    int size() const {
        return cima + 1;
    }
};


int main() {

    Pila<int> miPila;

    miPila.push(10);
    miPila.push(20);
    miPila.push(30);
    miPila.push(40);
    miPila.push(50);

    cout << "Tope: " << miPila.top() << endl; 
    miPila.pop();
    cout << "Nuevo tope: " << miPila.top() << endl;  

    while (!miPila.isEmpty()) {
        cout << "Elemento: " << miPila.top() << endl;
        miPila.pop();
    }

    return 0;
}