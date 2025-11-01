#include <iostream>
#include <map>

template<typename T>
struct Dnode {
    T data;
    Dnode<T>* next;
    Dnode<T>* prev;

    // Constructor para nodo normal
    Dnode(const T& val = T()) : data(val), next(nullptr), prev(nullptr) {}
};


// Función para inicializar una lista doblemente enlazada circular con nodo cabecera
template<typename T>
void init_list(Dnode<T>*& header) {
    header = new Dnode<T>(); // Nodo cabecera
    header->next = header;
    header->prev = header;
}   

// Inserta al final de la lista (antes del nodo cabecera)
template<typename T>
void insert_back(Dnode<T>* header, T val) {
    Dnode<T>* node = new Dnode<T>(val);
    node->prev = header->prev;
    node->next = header;
    header->prev->next = node;
    header->prev = node;
}

// Muestra la lista
template<typename T>
void print_list(Dnode<T>* header) {
    for (Dnode<T>* p = header->next; p != header; p = p->next)
        std::cout << p->data << " ";
    std::cout << std::endl;
}

// (a) Listas ORDENADAS
const bool similar_sorted(Dnode<int>& l1, Dnode<int>& l2) {
    Dnode<int>* p1 = l1.next;
    Dnode<int>* p2 = l2.next;

    while (p1 != &l1 && p2 != &l2) {
        if (p1->data != p2->data)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return (p1 == &l1 && p2 == &l2);
}

// (b) Listas NO ORDENADAS
const bool similar_unordered(Dnode<int>& l1, Dnode<int>& l2) {
    std::map<int, int> count1, count2;

    for (Dnode<int>* p = l1.next; p != &l1; p = p->next)
        count1[p->data]++;

    for (Dnode<int>* p = l2.next; p != &l2; p = p->next)
        count2[p->data]++;

    return count1 == count2;
}

int main() {
    Dnode<int>* l1;
    Dnode<int>* l2;

    init_list(l1);
    init_list(l2);

    // Ejemplo: listas ordenadas
    insert_back(l1, 1);
    insert_back(l1, 2);
    insert_back(l1, 3);

    insert_back(l2, 1);
    insert_back(l2, 2);
    insert_back(l2, 3);

    std::cout << "Lista 1: ";
    print_list(l1);
    std::cout << "Lista 2: ";
    print_list(l2);

    std::cout << "\n¿Son similares (ordenadas)? "
              << (similar_sorted(*l1, *l2) ? "Sí" : "No") << std::endl;

    // Cambiar orden para probar listas no ordenadas
    Dnode<int>* l3;
    Dnode<int>* l4;
    init_list(l3);
    init_list(l4);

    insert_back(l3, 4);
    insert_back(l3, 5);
    insert_back(l3, 6);
    insert_back(l3, 4);  // Duplicado

    insert_back(l4, 6);
    insert_back(l4, 4);
    insert_back(l4, 4);
    insert_back(l4, 5);  // Mismo contenido, distinto orden

    std::cout << "\nLista 3: ";
    print_list(l3);
    std::cout << "Lista 4: ";
    print_list(l4);

    std::cout << "\n¿Son similares (no ordenadas)? "
              << (similar_unordered(*l3, *l4) ? "Sí" : "No") << std::endl;

    return 0;
}
