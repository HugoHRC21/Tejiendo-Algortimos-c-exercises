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

    vector<Snode<T>*> nodes;
    for (Snode<T>* p = head; p; p = p->next) nodes.push_back(p);

    random_shuffle(nodes.begin(), nodes.end());

    for (auto p : nodes) {
        if (p->data == key) return p;
    }
    return nullptr;
}


template<typename T>
Snode<T>* random_select(Snode<T>* head) {
    if (!head) return nullptr;

    vector<Snode<T>*> nodes;
    for (Snode<T>* p = head; p; p = p->next) nodes.push_back(p);

    int idx = rand() % nodes.size();
    return nodes[idx];
}


template<typename T>
struct DisjointSet {
    vector<Snode<T>*> conjuntos;

    void make_set(T x) {
        conjuntos.push_back(new Snode<T>(x));
    }

    Snode<T>* find(T x) {
        for (auto head : conjuntos) {
            if (random_search(head, x)) {
                return head;
            }
        }
        return nullptr;
    }

    void union_sets(T x, T y) {
        Snode<T>* cx = find(x);
        Snode<T>* cy = find(y);
        if (!cx || !cy || cx == cy) return;

 
        Snode<T>* p = cx;
        while (p->next) p = p->next;
        p->next = cy;

        conjuntos.erase(remove(conjuntos.begin(), conjuntos.end(), cy), conjuntos.end());
    }
};

int main() {
    srand(time(0));

    DisjointSet<int> ds;


    ds.make_set(1);
    ds.make_set(2);
    ds.make_set(3);
    ds.make_set(4);


    ds.union_sets(1, 2);
    ds.union_sets(3, 4);


    cout << "Representante de 2: " << ds.find(2)->data << endl;
    cout << "Representante de 4: " << ds.find(4)->data << endl;


    Snode<int>* aleatorio = random_select(ds.find(1));
    cout << "Elemento aleatorio del conjunto {1,2}: " << aleatorio->data << endl;

    return 0;
}

