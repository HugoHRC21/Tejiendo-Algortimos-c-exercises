#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};


Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}


Node* find_min(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}


Node* find_max(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* delete_random(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->key)
        root->left = delete_random(root->left, key);
    else if (key > root->key)
        root->right = delete_random(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            if (rand() % 2 == 0) {
                Node* succ = find_min(root->right);
                root->key = succ->key;
                root->right = delete_random(root->right, succ->key);
            } else {
                Node* pred = find_max(root->left);
                root->key = pred->key;
                root->left = delete_random(root->left, pred->key);
            }
        }
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    srand(time(0)); 

    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    cout << "ABB original (inorden): ";
    inorder(root);
    cout << endl;

    root = delete_random(root, 3);

    cout << "ABB tras eliminación aleatoria: ";
    inorder(root);
    cout << endl;

    return 0;
}
