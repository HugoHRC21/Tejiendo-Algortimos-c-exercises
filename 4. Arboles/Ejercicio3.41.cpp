// 88. Diseñe un algoritmo que reciba como entrada el recorrido sujo de un árbol binario de
// búsqueda y retorne su IPL. No se debe construir el árbol.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int compute_IPL_from_postorder(const vector<int>& postorder) {
    if (postorder.empty()) return 0;

    vector<int> reversed(postorder.rbegin(), postorder.rend());

    stack<pair<int,int>> s; 
    int IPL = 0;

    s.push({reversed[0], 0});

    for (size_t i = 1; i < reversed.size(); ++i) {
        int val = reversed[i];
        int depth = 0;
        pair<int,int> last;

        while (!s.empty() && val < s.top().first) {
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
    vector<int> postorder = {1, 7, 6, 3, 13, 14, 10, 8};

    int ipl = compute_IPL_from_postorder(postorder);
    cout << "El IPL del ABB dado por el recorrido sufijo es: " << ipl << endl;

    return 0;
}
