#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string value;
    vector<Node*> children;  
    Node(string v) : value(v) {}
};

struct DeweyEntry {
    string value;
    string code;
};

void generateDewey(Node* root, string code, vector<DeweyEntry>& deweyArray) {
    if (!root) return;

    cout << root->value << " → " << code << endl;

    deweyArray.push_back({root->value, code});

    for (size_t i = 0; i < root->children.size(); i++) {
        string childCode = code + "." + to_string(i + 1);
        generateDewey(root->children[i], childCode, deweyArray);
    }
}

int main() {
    Node* A = new Node("A");
    Node* B = new Node("B");
    Node* C = new Node("C");
    Node* D = new Node("D");
    Node* E = new Node("E");
    Node* F = new Node("F");

    A->children = {B, C, D};
    C->children = {E, F};


    vector<DeweyEntry> deweyArray;


    generateDewey(A, "1", deweyArray);

    cout << "\n=== Arreglo con Dewey ===" << endl;
    for (auto& entry : deweyArray) {
        cout << entry.value << " → " << entry.code << endl;
    }


}
