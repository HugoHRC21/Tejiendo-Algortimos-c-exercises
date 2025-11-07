#include <iostream>
#include <stack>

using namespace std;

template<typename T>
struct Dnode {
    T data;
    Dnode<T>* prev;
    Dnode<T>* next;
    Dnode(const T& d) : data(d), prev(nullptr), next(nullptr) {}
};


template<typename T>
Dnode<T>* ultimoNodo(Dnode<T>* head) {
    while (head && head->next) head = head->next;
    return head;
}


template<typename T>
Dnode<T>* particion(Dnode<T>* low, Dnode<T>* high) {
    T pivote = high->data;
    Dnode<T>* i = low->prev;

    for (Dnode<T>* j = low; j != high; j = j->next) {
        if (j->data <= pivote) {
            i = (i == nullptr) ? low : i->next;
            std::swap(i->data, j->data);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i->data, high->data);
    return i;
}


template<typename T>
void quicksortNoRecursivo(Dnode<T>* head) {
    if (!head) return;

    Dnode<T>* h = ultimoNodo(head);
    stack<pair<Dnode<T>*, Dnode<T>*>> pila;
    pila.push({head, h});

    while (!pila.empty()) {
        auto [low, high] = pila.top();
        pila.pop();

        if (low && high && low != high && low != high->next) {
            Dnode<T>* p = particion(low, high);

            if (p->prev && low != p->prev)
                pila.push({low, p->prev});

            if (p->next && high != p->next)
                pila.push({p->next, high});
        }
    }
}

template<typename T>
void insertarFinal(Dnode<T>*& head, const T& valor) {
    Dnode<T>* nuevo = new Dnode<T>(valor);
    if (!head) {
        head = nuevo;
        return;
    }
    Dnode<T>* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = nuevo;
    nuevo->prev = temp;
}

template<typename T>
void imprimir(Dnode<T>* head) {
    for (Dnode<T>* p = head; p; p = p->next)
        cout << p->data << " ";
    cout << "\n";
}


int main() {
    Dnode<int>* lista = nullptr;
    insertarFinal(lista, 4);
    insertarFinal(lista, 1);
    insertarFinal(lista, 3);
    insertarFinal(lista, 2);
    insertarFinal(lista, 5);

    std::cout << "Lista original: ";
    imprimir(lista);

    quicksortNoRecursivo(lista);

    std::cout << "Lista ordenada: ";
    imprimir(lista);
}
