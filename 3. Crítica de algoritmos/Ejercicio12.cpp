#include <iostream>
#include <string>

using namespace std;

int encontrarFaltanteBruto(int A[], int n, int m) {
    for (int i = 0; i <= m; ++i) {
        bool encontrado = false;
        for (int j = 0; j < n; ++j) {
            if (A[j] == i) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) return i; 
    }
    return -1; 
}

int main() {
    int A[] = {0, 1, 2, 490, 4, 5, 6, 8};
    int n = sizeof(A) / sizeof(A[0]);
    int m = 491;

    int faltante = encontrarFaltanteBruto(A, n, m);
    cout << "Faltante: " << faltante << endl;

    return 0;
}
