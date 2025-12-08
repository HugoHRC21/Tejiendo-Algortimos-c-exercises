// 118. Diseñe un algoritmo iterativo eficiente que efectúe la unión de dos árboles binarios (+)

#include <iostream>
#include <stack>
#include <set>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int value) {
    Node** current = &root;
    while (*current) {
        if (value < (*current)->value)
            current = &((*current)->left);
        else if (value > (*current)->value)
            current = &((*current)->right);
        else
            return;
    }
    *current = new Node(value);
}

Node* union_trees(Node* rootA, Node* rootB) {
    stack<Node*> stackA, stackB;
    Node* currA = rootA;
    Node* currB = rootB;
    Node* result = nullptr;

    while ((currA || !stackA.empty()) || (currB || !stackB.empty())) {
        while (currA) {
            stackA.push(currA);
            currA = currA->left;
        }
        while (currB) {
            stackB.push(currB);
            currB = currB->left;
        }

        if (stackB.empty() || (!stackA.empty() && stackA.top()->value < stackB.top()->value)) {
            currA = stackA.top(); stackA.pop();
            insert(result, currA->value);
            currA = currA->right;
        }
        else if (stackA.empty() || (!stackB.empty() && stackB.top()->value < stackA.top()->value)) {
            currB = stackB.top(); stackB.pop();
            insert(result, currB->value);
            currB = currB->right;
        }
        else {
            currA = stackA.top(); stackA.pop();
            currB = stackB.top(); stackB.pop();
            insert(result, currA->value);
            currA = currA->right;
            currB = currB->right;
        }
    }

    return result;
}

void print_inorder(Node* root) {
    if (!root) return;
    print_inorder(root->left);
    cout << root->value << " ";
    print_inorder(root->right);
}

int main() {
    Node* A = nullptr;
    Node* B = nullptr;

    // Árbol A
    insert(A, 5);
    insert(A, 3);
    insert(A, 8);
    insert(A, 2);
    insert(A, 6);
    insert(A, 9);

    // Árbol B
    insert(B, 7);
    insert(B, 4);
    insert(B, 9);
    insert(B, 3);

    cout << "Árbol A (inorden): "; print_inorder(A); cout << endl;
    cout << "Árbol B (inorden): "; print_inorder(B); cout << endl;

    Node* result = union_trees(A, B);
    cout << "Unión (inorden): "; print_inorder(result); cout << endl;

    return 0;
}
