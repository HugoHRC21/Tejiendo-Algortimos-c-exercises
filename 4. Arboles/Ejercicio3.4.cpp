// Ejercicio 5(Arboles))Diseñe un algoritmo que busque una clave en un árbol n-ario representado mediante
// listas enlazadas. Discuta sobre las diferentes estrategias de búsqueda.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;  
    Node(string v) : value(v) {}
};

//La función se llama recursivamente para cada uno de sus hijos lo que permite 
//que se hunda en la busqueda en cada rama hasta el final antes de pasar a 
//buscar en la siquiente rama y asi sucesivamente.

Node* search_dfs(Node* root, const string& key) {
    if (!root) return nullptr;
    if (root->value == key) return root;

    for (Node* child : root->children) {
        Node* found = search_dfs(child, key);
        if (found) return found;
    }
    return nullptr;
}


//aca la funcion lo que hace es trabajar con una cola para ir agregando cada nivel 
//por completo y recorrer primero por amplitud para que luego de hacerlo recorrar 
//los siguentes niveles y su amplitud y asi sucesivamente

Node* search_bfs(Node* root, const string& key) {
    if (!root) return nullptr;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front(); 
        q.pop();

        if (current->value == key) return current;

        for (Node* child : current->children) {
            if (child) q.push(child);
        }
    }
    return nullptr;
}



int main() {
    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    Node* d = new Node("D");
    Node* e = new Node("E");
    Node* f = new Node("F");

    a->children = {b, c, d};
    c->children = {e, f};

    Node* result_dfs = search_dfs(a, "F");
    cout << "DFS encontró: " << (result_dfs ? result_dfs->value : "No encontrado") << endl;

    Node* result_bfs = search_bfs(a, "E");
    cout << "BFS encontró: " << (result_bfs ? result_bfs->value : "No encontrado") << endl;

    return 0;
}
