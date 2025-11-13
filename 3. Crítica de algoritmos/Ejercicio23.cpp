#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
struct Snode {
    T data;
    Snode<T>* next;
    Snode(const T& d) : data(d), next(nullptr) {}
};

template<typename T>
void quicksortIterativo(Snode<T>** head) {
    vector<Snode<T>*> v;
    for (Snode<T>* p = *head; p; p = p->next)
        v.push_back(p);
    if (v.size() < 2) return;

    stack<pair<int,int>> pila;
    pila.push({0, (int)v.size() - 1});

    while (!pila.empty()) {
        auto [l, r] = pila.top();
        pila.pop();
        if (l >= r) continue;

        T pivote = v[r]->data;
        int i = l;
        for (int j = l; j < r; ++j) {
            if (v[j]->data < pivote)
                std::swap(v[i++], v[j]);
        }
        swap(v[i], v[r]);

        pila.push({l, i - 1});
        pila.push({i + 1, r});
    }

    for (size_t i = 0; i + 1 < v.size(); ++i)
        v[i]->next = v[i + 1];
    v.back()->next = nullptr;
    *head = v.front();
}

template<typename T>
void insertarFinal(Snode<T>*& head, const T& valor) {
    Snode<T>* nuevo = new Snode<T>(valor);
    if (!head) {
        head = nuevo;
        return;
    }
    Snode<T>* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = nuevo;
}

template<typename T>
void imprimir(Snode<T>* head) {
    for (Snode<T>* p = head; p; p = p->next)
        cout << p->data << " ";
    cout << "\n";
}

int main() {
    Snode<int>* lista = nullptr;
    insertarFinal(lista, 4);
    insertarFinal(lista, 1);
    insertarFinal(lista, 6);
    insertarFinal(lista, 2);
    insertarFinal(lista, 5);

    cout << "Lista original: ";
    imprimir(lista);

    quicksortIterativo(&lista);

    cout << "Lista ordenada: ";
    imprimir(lista);
}
