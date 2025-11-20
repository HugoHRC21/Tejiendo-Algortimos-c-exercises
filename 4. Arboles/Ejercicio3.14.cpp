//19. Dado un árbol binario, diseñe un algoritmo que efectúe la copia hilada.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
    Node(string v) : value(v), left(nullptr), right(nullptr) {}
};

struct ThreadedNode {
    string value;
    ThreadedNode* left;
    ThreadedNode* right;
    bool leftThread;
    bool rightThread;

    ThreadedNode(string v)
        : value(v), left(nullptr), right(nullptr),
          leftThread(false), rightThread(false) {}
};

ThreadedNode* copy_threaded(Node* root, ThreadedNode*& prev) {
    if (!root) return nullptr;

    ThreadedNode* leftCopy = copy_threaded(root->left, prev);

    ThreadedNode* current = new ThreadedNode(root->value);

    if (leftCopy) {
        current->left = leftCopy;
    } else {
        current->left = prev;     
        current->leftThread = true;
    }

    if (prev && !prev->right) {
        prev->right = current;
        prev->rightThread = true;
    }

    prev = current;

    ThreadedNode* rightCopy = copy_threaded(root->right, prev);
    if (rightCopy) {
        current->right = rightCopy;
    }

    return current;
}

ThreadedNode* copy_to_threaded(Node* root) {
    ThreadedNode* prev = nullptr;
    return copy_threaded(root, prev);
}

void inorder_traversal(ThreadedNode* root) {
    if (!root) return;
    ThreadedNode* current = root;


    while (current->left && !current->leftThread) {
        current = current->left;
    }

    while (current) {
        cout << current->value << " ";

        if (current->rightThread) {
            current = current->right;
        } else {
            current = current->right;
            while (current && current->left && !current->leftThread) {
                current = current->left;
            }
        }
    }
}

int main() {

    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");

    A->left = B; A->right = C;
    B->left = D; B->right = E;

    ThreadedNode* threadedRoot = copy_to_threaded(A);

    cout << "Recorrido inorden (arbol hilado): ";
    inorder_traversal(threadedRoot);
    cout << endl;

    return 0;
}
