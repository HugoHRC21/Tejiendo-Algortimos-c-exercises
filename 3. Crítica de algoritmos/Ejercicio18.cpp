#include <iostream>

using namespace std;

// METODO DE MEZCLA, ES DECIR, DIVIDE LA LISTA A LA MITAD REPETIDAMENTE, ORDENA CADA MITAD Y LUEGO MEZCLA DE FORMA ORDENADA // 

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
    Nodo(const T& d) : dato(d), siguiente(nullptr) {}
};

template <typename T>
void dividir(Nodo<T>* lista, Nodo<T>** frente, Nodo<T>** atras) {
    Nodo<T>* lento = lista;
    Nodo<T>* rapido = lista->siguiente;

    while (rapido && rapido->siguiente) {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    *frente = lista;
    *atras = lento->siguiente;
    lento->siguiente = nullptr;
}

template <typename T>
Nodo<T>* fusionar(Nodo<T>* lista1, Nodo<T>* lista2) {
    if (!lista1) return lista2;
    if (!lista2) return lista1;

    if (lista1->dato <= lista2->dato) {
        lista1->siguiente = fusionar(lista1->siguiente, lista2);
        return lista1;
    } else {
        lista2->siguiente = fusionar(lista1, lista2->siguiente);
        return lista2;
    }
}


template <typename T>
void ordenamientoMezcla(Nodo<T>** cabeza) {
    if (!*cabeza || !(*cabeza)->siguiente) return;

    Nodo<T>* lista1;
    Nodo<T>* lista2;

    dividir(*cabeza, &lista1, &lista2);

    ordenamientoMezcla(&lista1);
    ordenamientoMezcla(&lista2);

    *cabeza = fusionar(lista1, lista2);
}

template <typename T>
void imprimirLista(Nodo<T>* cabeza) {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << "\n";
}


int main() {
    Nodo<int>* lista = new Nodo<int>(4);
    lista->siguiente = new Nodo<int>(2);
    lista->siguiente->siguiente = new Nodo<int>(5);
    lista->siguiente->siguiente->siguiente = new Nodo<int>(1);
    lista->siguiente->siguiente->siguiente->siguiente = new Nodo<int>(3);

    cout << "Lista original: ";
    imprimirLista(lista);

    ordenamientoMezcla(&lista);

    cout << "Lista ordenada: ";
    imprimirLista(lista);


    while (lista != nullptr) {
        Nodo<int>* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    return 0;
}
