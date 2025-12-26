// 29. Para los siguientes árboles AVL, denidos por sus recorridos prejos, ejecute las secuencias de eliminación dadas:
// (a) Prejo: 136 103 62 22 19 12 55 45 86 70 99 123 121 126 134 181 152 142 147 158 193 189
// 205 199 235
// Secuencia de eliminación: 99 123 121 181 134 193 12 22 45 205 62 189
// (b) Prejo: 128 41 28 21 8 24 29 93 54 49 84 117 94 207 158 146 143 157 182 190 225 211
// 213 244 235
// Secuencia de eliminación: 41 54 29 211 28 235 128 84 24 182 146 8
// (c) Prejo: 110 49 29 11 1 21 39 91 80 77 102 97 191 173 156 151 172 184 181 219 210 209
// 227 226 230
// Secuencia de eliminación: 80 21 49 226 181 39 11 91 29 172 184 97
// (d) Prejo: 151 47 44 7 1 35 46 115 93 71 94 140 126 218 203 184 183 201 192 213 207 232
// 231 227 243
// Secuencia de eliminación: 184 227 213 207 46 47 151 44 231 115 94 7
// (e) Prejo: 172 131 89 69 27 110 106 116 155 141 137 152 158 194 185 176 193 190 222 201
// 217 244 236 231 245
// Secuencia de eliminación: 185 131 201 176 69 194 190 172 217 236 152 158


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int h(Node* n){ return n ? n->height : 0; }
int balance(Node* n){ return n ? h(n->left) - h(n->right) : 0; }

void update(Node* n){
    n->height = 1 + max(h(n->left), h(n->right));
}

Node* rotateRight(Node* y){
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    update(y); update(x);
    return x;
}

Node* rotateLeft(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    update(x); update(y);
    return y;
}

Node* insertAVL(Node* root, int key){
    if(!root) return new Node(key);

    if(key < root->key) 
        root->left = insertAVL(root->left, key);
    else 
        root->right = insertAVL(root->right, key);

    update(root);

    int b = balance(root);

    if(b > 1 && key < root->left->key) return rotateRight(root);     // LL
    if(b < -1 && key > root->right->key) return rotateLeft(root);     // RR
    if(b > 1 && key > root->left->key){                               // LR
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(b < -1 && key < root->right->key){                             // RL
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

Node* minNode(Node* n){
    while(n->left) n = n->left;
    return n;
}

Node* deleteAVL(Node* root, int key){
    if(!root) return nullptr;

    if(key < root->key) root->left = deleteAVL(root->left, key);
    else if(key > root->key) root->right = deleteAVL(root->right, key);
    else {
        if(!root->left || !root->right){
            Node* t = root->left ? root->left : root->right;
            if(!t){
                delete root;
                return nullptr;
            } else {
                *root = *t;
                delete t;
            }
        } else {
            Node* t = minNode(root->right);
            root->key = t->key;
            root->right = deleteAVL(root->right, t->key);
        }
    }

    update(root);

    int b = balance(root);

    if(b > 1 && balance(root->left) >= 0) return rotateRight(root);           // LL
    if(b > 1 && balance(root->left) < 0){                                     // LR
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(b < -1 && balance(root->right) <= 0) return rotateLeft(root);          // RR
    if(b < -1 && balance(root->right) > 0){                                   // RL
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void printAVL(Node* root, int space = 0, int indent = 6){
    if(!root) return;
    space += indent;
    printAVL(root->right, space);
    cout << "\n";
    for(int i = indent; i < space; i++) cout << " ";
    cout << root->key;
    printAVL(root->left, space);
}


int main(){
    vector<int> prefijo = {
        136,103,62,22,19,12,55,45,86,70,99,123,121,126,134,
        181,152,142,147,158,193,189,205,199,235
    };
    vector<int> eliminar = {99,123,121,181,134,193,12,22,45,205,62,189};

    Node* T = nullptr;

    // construir desde prefijo simplemente insertando en orden
    for (int x : prefijo)
        T = insertAVL(T, x);

    // eliminar elementos
    for (int x : eliminar)
        T = deleteAVL(T, x);

    cout << "AVL final:\n";
    printAVL(T);
    cout << "\n";
    return 0;
}
