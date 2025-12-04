// 97. Diseñe un algoritmo recursivo que calcule la posición infija de una clave del árbol.

 #include <iostream>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
    Node(char v) : value(v), left(nullptr), right(nullptr) {}
};

int inorder_position(Node* root, char key, int& count) {
    if (!root) return -1;  

    int pos = inorder_position(root->left, key, count);
    if (pos != -1) return pos;  

    count++;  
    if (root->value == key)
        return count; 

    return inorder_position(root->right, key, count);
}

int get_inorder_position(Node* root, char key) {
    int count = 0;
    return inorder_position(root, key, count);
}

int main() {
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;


    cout << "Posición infija de D: " << get_inorder_position(A, 'D') << endl;
    cout << "Posición infija de B: " << get_inorder_position(A, 'B') << endl;
    cout << "Posición infija de E: " << get_inorder_position(A, 'E') << endl;
    cout << "Posición infija de A: " << get_inorder_position(A, 'A') << endl;
    cout << "Posición infija de C: " << get_inorder_position(A, 'C') << endl;

    return 0;
}
