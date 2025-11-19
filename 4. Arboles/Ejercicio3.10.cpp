#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T v) : value(v), left(nullptr), right(nullptr) {}
};


template <typename T>
Node<T>* build_tree(
    const vector<T>& inorder,
    const vector<T>& postorder,
    int in_start,
    int in_end,
    int& post_index,
    unordered_map<T, int>& inorder_map
    ) {
        if (in_start > in_end) return nullptr;

        
        T root_val = postorder[post_index--];
        Node<T>* root = new Node<T>(root_val);


        if (in_start == in_end) return root;

     
        int in_index = inorder_map[root_val];

        root->right = build_tree(inorder, postorder, in_index + 1, in_end, post_index, inorder_map);

        root->left = build_tree(inorder, postorder, in_start, in_index - 1, post_index, inorder_map);

        return root;
}




template <typename T>
Node<T>* construct_from_in_post(const vector<T>& inorder, const vector<T>& postorder) {
    int n = inorder.size();
    int post_index = n - 1;


    unordered_map<T, int> inorder_map;
    for (int i = 0; i < n; i++) {
        inorder_map[inorder[i]] = i;
    }
    return build_tree(inorder, postorder, 0, n - 1, post_index, inorder_map);
}





template <typename T>
void print_preorder(Node<T>* root) {
    if (!root) return;
    cout << root->value << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}



int main() {
    // Ejemplo
    vector<char> inorder   = {'D', 'B', 'E', 'A', 'F', 'C'};
    vector<char> postorder = {'D', 'E', 'B', 'F', 'C', 'A'};

    Node<char>* root = construct_from_in_post(inorder, postorder);

    cout << "Preorden del árbol reconstruido: ";
    print_preorder(root);  
    cout << endl;

    return 0;
}
