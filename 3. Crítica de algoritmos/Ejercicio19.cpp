#include <iostream>
#include <vector>
#include <stack>

using namespace std;


// METODO quizsort

template<typename T>
struct Snode {
    T data;
    Snode<T>* next;
    Snode(const T& d) : data(d), next(nullptr) {}
}; 

template<typename T>
void quicksortIterativo(Snode<T>** head) {

    vector<Snode<T>*> v;
    for (Snode<T>* p = *head; p; p = p->next) v.push_back(p);
    if (v.size() < 2) return;

    // Quicksort iterativo
    stack<pair<int,int>> pila;
    pila.push({0, (int)v.size()-1});
    while (!pila.empty()) {
        auto [l, r] = pila.top(); pila.pop();
        if (l >= r) continue;
        T piv = v[r]->data;
        int i = l;
        for (int j = l; j < r; ++j)
            if (v[j]->data < piv) {
                swap(v[i++], v[j]);
                };
        swap(v[i], v[r]);
        pila.push({l, i-1});
        pila.push({i+1, r});
    }

    for (size_t i = 0; i + 1 < v.size(); ++i) v[i]->next = v[i+1];
    v.back()->next = nullptr;
    *head = v.front();
}

template<typename T>
void imprimir(Snode<T>* p) {
    while (p) {cout << p->data << " "; p = p->next; }
    cout << "\n";
}

int main() {
    Snode<int>* lista = new Snode<int>(34);
    lista->next = new Snode<int>(22);
    lista->next->next = new Snode<int>(565);
    lista->next->next->next = new Snode<int>(211);
    lista->next->next->next->next = new Snode<int>(32);

    cout << "Lista original: ";
    imprimir(lista);

    quicksortIterativo(&lista);

    cout << "Lista ordenada: ";
    imprimir(lista);

    while (lista) { auto t = lista; lista = lista->next; delete t; }
}
