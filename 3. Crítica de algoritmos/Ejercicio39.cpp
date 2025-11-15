/* RANDOM SELECT*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Snode {
    T data;
    Snode* next;
    Snode(T d) : data(d), next(nullptr) {}
};

template<typename T>
Snode<T>* random_select(Snode<T>* head, int k) {
    if (!head) return nullptr;  


    if (!head->next) return head;


    int n = 0;
    for (Snode<T>* p = head; p; p = p->next) n++;

    int pivIndex = rand() % n;   
    Snode<T>* pivNode = head;
    for (int i = 0; i < pivIndex; i++) pivNode = pivNode->next;
    T pivot = pivNode->data;

    Snode<T>* less = nullptr, *equal = nullptr, *greater = nullptr;
    for (Snode<T>* p = head; p; ) {
        Snode<T>* nxt = p->next;
        if (p->data < pivot) {
            p->next = less; less = p;
        } else if (p->data == pivot) {
            p->next = equal; equal = p;
        } else {
            p->next = greater; greater = p;
        }
        p = nxt;
    }

    int lessCount = 0, equalCount = 0;
    for (Snode<T>* p = less; p; p = p->next) lessCount++;
    for (Snode<T>* p = equal; p; p = p->next) equalCount++;


    if (k <= lessCount) {
        return random_select(less, k);
    } else if (k <= lessCount + equalCount) {
        return equal; 
    } else {
        return random_select(greater, k - lessCount - equalCount);
    }
}

int main() {
    srand(time(0)); 

    Snode<int>* head = new Snode<int>(7);
    head->next = new Snode<int>(2);
    head->next->next = new Snode<int>(9);
    head->next->next->next = new Snode<int>(4);
    head->next->next->next->next = new Snode<int>(1);

    int k = 3;
    Snode<int>* result = random_select(head, k);
    if (result)
        cout << k << "-ésimo menor elemento es: " << result->data << endl;
    else
        cout << "No encontrado." << endl;
}
