/* RANDOM SEARCH*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Snode {
    T data;
    Snode* next;
    Snode(T d) : data(d), next(nullptr) {}
};


template<typename T>
Snode<T>* random_search(Snode<T>* head, T key) {
    if (!head) return nullptr;


    int n = 0;
    for (Snode<T>* p = head; p; p = p->next) n++;

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);

    random_shuffle(indices.begin(), indices.end());


    for (int idx : indices) {
        Snode<T>* p = head;
        for (int i = 0; i < idx; i++) p = p->next;
        if (p->data == key) return p;              
    }

    return nullptr;
}

int main() {
    srand(time(0));


    Snode<int>* head = new Snode<int>(7);
    head->next = new Snode<int>(2);
    head->next->next = new Snode<int>(9);
    head->next->next->next = new Snode<int>(2);
    head->next->next->next->next = new Snode<int>(1);

    int valor = 9;
    Snode<int>* result = random_search(head, valor);

    if (result)
        cout << "Encontrado: " << result->data << endl;
    else
        cout << "No encontrado." << endl;

    return 0;
}


