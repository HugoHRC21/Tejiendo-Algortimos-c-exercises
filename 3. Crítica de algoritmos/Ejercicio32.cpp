#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


template <typename T>
struct Snode {
    T data;
    Snode* next;
    Snode(T val) : data(val), next(nullptr) {}
};

template <typename T>
T quickSelect(vector<T>& v, int l, int r, int k) {
    if (l == r) return v[l];

    int pivotIndex = l + rand() % (r - l + 1);
    T pivot = v[pivotIndex];

    vector<T> menores, mayores;
    for (int i = l; i <= r; i++) {
        if (i == pivotIndex) continue;
        if (v[i] < pivot)
            menores.push_back(v[i]);
        else
            mayores.push_back(v[i]);
    }

    if ((int)menores.size() == k)
        return pivot;
    else if ((int)menores.size() > k)
        return quickSelect(menores, 0, menores.size() - 1, k);
    else
        return quickSelect(mayores, 0, mayores.size() - 1, k - menores.size() - 1);
}

template <typename T>
T i_esimo_menor(Snode<T>* head, int i) {
    vector<T> valores;
    for (Snode<T>* p = head; p != nullptr; p = p->next)
        valores.push_back(p->data);

    if (i < 1 || i > (int)valores.size()) {
        throw out_of_range("i fuera de rango");
    }

    srand(time(nullptr));
    return quickSelect(valores, 0, valores.size() - 1, i - 1);
}


int main() {
    Snode<int>* lista = new Snode<int>(7);
    lista->next = new Snode<int>(2);
    lista->next->next = new Snode<int>(9);
    lista->next->next->next = new Snode<int>(1);
    lista->next->next->next->next = new Snode<int>(5);

    int i = 3; // queremos el 3er menor
    int valor = i_esimo_menor(lista, i);
    cout << "El " << i << "-ésimo menor elemento es: " << valor << endl;

    return 0;
}
