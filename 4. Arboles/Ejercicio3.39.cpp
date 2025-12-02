//86. Diseñe un algoritmo que tome como entrada el recorrido prejo e injo de un árbol y
// retorne como salida el recorrido por niveles. No se debe construir el árbol.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void print_level_order_from_pre_in(
    const vector<char>& preorder,
    const vector<char>& inorder)
{
    int n = preorder.size();
    if (n == 0) return;

    unordered_map<char, int> pos_inorder;
    for (int i = 0; i < n; ++i)
        pos_inorder[inorder[i]] = i;

    queue<tuple<int,int,int,int>> q;
    q.push({0, n-1, 0, n-1});

    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) {
            auto [preL, preR, inL, inR] = q.front();
            q.pop();

            if (preL > preR || inL > inR)
                continue;

            char root = preorder[preL];
            cout << root << " ";

            int rootPos = pos_inorder[root];
            int leftSize = rootPos - inL;
            int rightSize = inR - rootPos;

            if (leftSize > 0)
                q.push({preL + 1, preL + leftSize, inL, rootPos - 1});

            if (rightSize > 0)
                q.push({preL + leftSize + 1, preR, rootPos + 1, inR});
        }
    }
}

int main() {
    vector<char> preorder = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
    vector<char> inorder  = {'D', 'B', 'E', 'A', 'F', 'C', 'G'};

    cout << "Recorrido por niveles (sin construir árbol): ";
    print_level_order_from_pre_in(preorder, inorder);
    cout << endl;
}
