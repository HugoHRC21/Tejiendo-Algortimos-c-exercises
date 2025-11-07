#include <iostream>
using namespace std;


template<typename T>
struct Snode {
    T data;
    Snode<T>* next;
    Snode(const T& d) : data(d), next(nullptr) {}
};

template<typename T>
void dividir(Snode<T>* cabeza, Snode<T>** menores, Snode<T>** iguales, Snode<T>** mayores) {
    *menores = *iguales = *mayores = nullptr;
    if (!cabeza) return;

    T pivote = cabeza->data;
    while (cabeza) {
        Snode<T>* sig = cabeza->next;
        if (cabeza->data < pivote) {
            cabeza->next = *menores; *menores = cabeza;
        } else if (cabeza->data == pivote) {
            cabeza->next = *iguales; *iguales = cabeza;
        } else {
            cabeza->next = *mayores; *mayores = cabeza;
        }
        cabeza = sig;
    }
}

template<typename T>
Snode<T>* concatenar(Snode<T>* a, Snode<T>* b) {
    if (!a) return b;
    Snode<T>* p = a;
    while (p->next) p = p->next;
    p->next = b;
    return a;
}

template<typename T>
Snode<T>* quicksort(Snode<T>* cabeza) {
    if (!cabeza || !cabeza->next) return cabeza;

    Snode<T>* menores, *iguales, *mayores;
    dividir(cabeza, &menores, &iguales, &mayores);

    menores = quicksort(menores);
    mayores = quicksort(mayores);

    return concatenar(concatenar(menores, iguales), mayores);
}

template<typename T>
void imprimir(Snode<T>* p) {
    while (p) { std::cout << p->data << " "; p = p->next; }
    std::cout << "\n";
}

int main() {
    Snode<int>* lista = new Snode<int>(4);
    lista->next = new Snode<int>(2);
    lista->next->next = new Snode<int>(5);
    lista->next->next->next = new Snode<int>(1);
    lista->next->next->next->next = new Snode<int>(3);

    std::cout << "Lista original: ";
    imprimir(lista);

    lista = quicksort(lista);

    std::cout << "Lista ordenada: ";
    imprimir(lista);

    while (lista) { auto t = lista; lista = lista->next; delete t; }
}
