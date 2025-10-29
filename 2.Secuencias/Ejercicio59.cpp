#include <iostream>

struct Node {
    int data;       
    Node* next;     

    Node(int val) : data(val), next(nullptr) {} 
};

class LinkedList {
public:
    Node* head; 

    LinkedList() : head(nullptr) {} 

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode; 
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next; 
        }
        current->next = newNode; 
    }

    int countOccurrences(int x) {
        int count = 0; 
        Node* current = head; 

        while (current != nullptr) {
            if (current->data == x) {
                count++; 
            }
            current = current->next; 
        }
        return count;
    }

};

int main() {
    LinkedList list; 

   
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(4);

    int x = 2; 
    int occurrences = list.countOccurrences(x);

    cout << "El número de ocurrencias de " << x << " es: " << occurrences << std::endl;

    return 0;
}