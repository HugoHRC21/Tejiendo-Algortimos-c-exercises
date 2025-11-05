#include <iostream>
using namespace std;


// METODO DE SELECCION, ES DECIR, ENCONTRAR EL MINIMO DE LA LISTA NO ORDENADA Y COLOCARLO AL PRINCIPIO// 
struct Snode {
    int data;
    Snode* next;
};

void selectionSort(Snode* head) {
    for (Snode* i = head; i != nullptr; i = i->next) {
        Snode* minNode = i;
        for (Snode* j = i->next; j != nullptr; j = j->next) {
            if (j->data < minNode->data) {
                minNode = j;
            }
        }
        int temp = i->data;
        i->data = minNode->data;
        minNode->data = temp;
    }
}

void printList(Snode* head) {
    for (Snode* p = head; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}

int main() {
    Snode a{4, nullptr};
    Snode b{2, nullptr};
    Snode c{7, nullptr};
    Snode d{1, nullptr};
    Snode e{3, nullptr};
    a.next = &b; b.next = &c; c.next = &d; d.next = &e;

    cout << "Antes: ";
    printList(&a);

    selectionSort(&a);

    cout << "Después: ";
    printList(&a);
}
