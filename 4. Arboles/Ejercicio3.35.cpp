// 61. Diseñe un algoritmo que construya un árbol binario de búsqueda a partir de su recorrido
// sujo

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* insert_bst(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->value)
        root->left = insert_bst(root->left, value);
    else
        root->right = insert_bst(root->right, value);
    return root;
}

Node* build_bst_from_postorder(const vector<int>& postorder) {
    if (postorder.empty()) return nullptr;

    Node* root = new Node(postorder.back());

    for (int i = postorder.size() - 2; i >= 0; --i) {
        root = insert_bst(root, postorder[i]);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

int main() {
    // Ejemplo: postorden
    vector<int> postorder = {1, 7, 5, 50, 40, 10};

    Node* root = build_bst_from_postorder(postorder);

    cout << "Inorden del ABB construido: ";
    inorder(root);
    cout << endl;

    return 0;
}
