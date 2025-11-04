#include <iostream>
#include <string>

using namespace std;

class Dicolas {
private:
    int* datos;
    int capacidad;
    int frente;
    int fin;
    int numElementos;

public:
    Dicolas(int cap) {
        capacidad = cap;
        datos = new int[capacidad];
        frente = -1;
        fin = 0;
        numElementos = 0;
    }

    void insertarFrente(int valor) {
        if (numElementos == capacidad) {
            cout << "Dicolas llena, no se puede insertar al frente." << endl;
            return;
        }
        frente = (frente + 1) % capacidad;
        datos[frente] = valor;
        numElementos++;
    }

    void insertarFin(int valor) {
        if (numElementos == capacidad) {
            cout << "Dicolas llena, no se puede insertar al final." << endl;
            return;
        }
        fin = (fin - 1 + capacidad) % capacidad;
        datos[fin] = valor;
        numElementos++;
    }

    void eliminarFrente() {
        if (esVacia()) {
            cout << "Dicolas vacía, no se puede eliminar del frente." << endl;
            return;
        }
        frente = (frente - 1 + capacidad) % capacidad;
        numElementos--;
    }

    void eliminarFin() {
        if (esVacia()) {
            cout << "Dicolas vacía, no se puede eliminar del final." << endl;
            return;
        }
        fin = (fin + 1) % capacidad;
        numElementos--;
    }

    bool esVacia() {
        return numElementos == 0;
    }

    int obtenerFrente() {
        if (esVacia()) {
            throw runtime_error("Dicolas vacía.");
        }
        return datos[frente];
    }

    int obtenerFin() {
        if (esVacia()) {
            throw runtime_error("Dicolas vacía.");
        }
        return datos[fin];
    }

    int tamaño() {
        return numElementos;
    }
};

int main() {
    Dicolas d(5);

    d.insertarFrente(10);
    d.insertarFin(20);
    d.insertarFrente(5);
    
    cout << "Frente: " << d.obtenerFrente() << endl; 
    cout << "Fin: " << d.obtenerFin() << endl;   
    cout << "Tamaño: " << d.tamaño() << endl;  

    d.eliminarFrente();
    cout << "Frente después de eliminar: " << d.obtenerFrente() << endl; 

    d.eliminarFin();
    cout << "Fin después de eliminar: " << d.obtenerFin() << endl;     

    return 0;
}