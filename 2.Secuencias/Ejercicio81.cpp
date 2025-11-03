#include <iostream>
#include <stdexcept>  
using namespace std;

#include <iostream>
#include <stdexcept>

template <typename T>
class Cola {
private:
    T* datos;
    int capacidad;
    int frente;
    int final;
    int cantidad;

    void redimensionar() {
        int nuevaCapacidad = capacidad * 2;
        T* nuevoArreglo = new T[nuevaCapacidad];

        for (int i = 0; i < cantidad; ++i) {
            nuevoArreglo[i] = datos[(frente + i) % capacidad];
        }

        delete[] datos;
        datos = nuevoArreglo;
        capacidad = nuevaCapacidad;
        frente = 0;
        final = cantidad;
    }

public:
    Cola() {
        capacidad = 10;
        datos = new T[capacidad];
        frente = 0;
        final = 0;
        cantidad = 0;
    }

    ~Cola() {
        delete[] datos;
    }

    void encolar(const T& elemento) {
        if (cantidad == capacidad) {
            redimensionar();
        }

        datos[final] = elemento;
        final = (final + 1) % capacidad;
        ++cantidad;
    }

    void desencolar() {
        if (estaVacia()) {
            throw runtime_error("La cola está vacía. No se puede desencolar.");
        }

        frente = (frente + 1) % capacidad;
        --cantidad;
    }

    T frenteElemento() const {
        if (estaVacia()) {
            throw runtime_error("La cola está vacía.");
        }

        return datos[frente];
    }

    bool estaVacia() const {
        return cantidad == 0;
    }

    int tamanio() const {
        return cantidad;
    }
};


int main() {
    Cola<int> cola;

    cola.encolar(20);
    cola.encolar(40);
    cola.encolar(60);
    cola.encolar(80);

    cout << "Frente: " << cola.frenteElemento() << endl;

    cola.desencolar();
    cout << "Nuevo frente: " << cola.frenteElemento() << endl; 

    while (!cola.estaVacia()) {
        cout << "Elemento: " << cola.frenteElemento() << endl;
        cola.desencolar();
    }

    cout << "Tamano final: " << cola.tamanio() << endl; 
    return 0;
}
