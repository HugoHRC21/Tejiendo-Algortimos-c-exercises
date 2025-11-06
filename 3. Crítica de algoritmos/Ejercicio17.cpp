#include <iostream>
using namespace std;

// METODO DE INSERCION, ES DECIR, CADA ELEMENTO DE LA LISTA EN SU POSICION CORRECTA EN LA // 

struct Snode {
    int data;
    Snode* next;
    Snode(int v) : data(v), next(nullptr) {}
};

void insertionSort(Snode*& head) {
    Snode* sorted = nullptr;

    while (head) {
        Snode* n = head;       
        head = head->next;     

        if (!sorted || n->data < sorted->data) {
            n->next = sorted;
            sorted = n;
        } else {
            Snode* cur = sorted;
            while (cur->next && cur->next->data < n->data)
                cur = cur->next;
            n->next = cur->next;
            cur->next = n;
        }
    }

    head = sorted;
}

void printList(Snode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Snode* head = new Snode(4);
    head->next = new Snode(2);
    head->next->next = new Snode(5);
    head->next->next->next = new Snode(1);
    head->next->next->next->next = new Snode(3);

    cout << "Antes: ";
    printList(head);

    insertionSort(head);

    cout << "Despues: ";
    printList(head);
}
