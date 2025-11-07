#include <iostream>
using namespace std;

template<typename T>
struct Snode {
    T data;
    Snode<T>* next;
    Snode() : next(this) {} 
    Snode(const T& d) : data(d), next(nullptr) {} 
};


template<typename T>
void insertarInicio(Snode<T>& cabecera, Snode<T>* nodo) {
    nodo->next = cabecera.next;
    cabecera.next = nodo;
}

template<typename T>
Snode<T>* partir(Snode<T>& list, Snode<T>& l1, Snode<T>& l2) {
    if (list.next == &list) return nullptr;

    Snode<T>* pivote = list.next;
    Snode<T>* actual = pivote->next;

    list.next = &list;


    while (actual != &list) {
        Snode<T>* siguiente = actual->next; 

        if (actual->data < pivote->data)
            insertarInicio(l1, actual);
        else if (actual->data > pivote->data)
            insertarInicio(l2, actual);

        actual = siguiente;
    }

   
    pivote->next = pivote;

    return pivote;
}

template<typename T>
void imprimirLista(const Snode<T>& cabecera) {
    Snode<T>* p = cabecera.next;
    while (p != &cabecera) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main() {
    Snode<int> lista, menores, mayores;

    insertarInicio(lista, new Snode<int>(5));
    insertarInicio(lista, new Snode<int>(2));
    insertarInicio(lista, new Snode<int>(6));
    insertarInicio(lista, new Snode<int>(1));
    insertarInicio(lista, new Snode<int>(4));

    std::cout << "Lista original: ";
    imprimirLista(lista);

    Snode<int>* piv = partir(lista, menores, mayores);

    cout << "Pivote: " << piv->data << "\n";
    cout << "Menores: ";
    imprimirLista(menores);
    cout << "Mayores: ";
    imprimirLista(mayores);
    cout << "Lista original vacía: ";
    imprimirLista(lista);

    delete piv; // liberar pivote
}
