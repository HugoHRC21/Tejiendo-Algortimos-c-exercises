// 87. Diseñe un algoritmo que reciba como entrada el recorrido prejo de un árbol binario
// de búsqueda y retorne su IPL. No se debe construir el árbol.

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int compute_IPL_from_preorder(const vector<int>& preorder) {
    if (preorder.empty()) return 0;

    stack<pair<int,int>> s; 
    int IPL = 0;

    s.push({preorder[0], 0}); 

    for (size_t i = 1; i < preorder.size(); ++i) {
        int depth = 0;
        int val = preorder[i];

        pair<int,int> last;
        while (!s.empty() && val > s.top().first) {
            last = s.top();
            s.pop();
        }

        if (s.empty())
            depth = last.second + 1; 
        else
            depth = s.top().second + 1; 

        IPL += depth;
        s.push({val, depth});
    }   

    return IPL;
}

int main() {
    vector<int> preorder = {8, 3, 1, 6, 4, 7, 10, 14, 13};

    int ipl = compute_IPL_from_preorder(preorder);
    cout << "El IPL del ABB dado por el recorrido prefijo es: " << ipl << endl;

    return 0;
}
