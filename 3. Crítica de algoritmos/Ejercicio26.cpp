#include <bits/stdc++.h>
using namespace std;


template <typename T>
int select_pivot(T a[], const int l, const int r, const int n) {
    vector<int> indices;
    indices.reserve(n);

    for (int i = 0; i < n; i++) {
        int idx = l + rand() % (r - l + 1);
        indices.push_back(idx);
    }


    vector<T> valores;
    valores.reserve(n);
    for (int idx : indices)
        valores.push_back(a[idx]);

    sort(valores.begin(), valores.end());

    T mediana = valores[n / 2];

    for (int idx : indices) {
        if (a[idx] == mediana)
            return idx;
    }

    return indices[0];
}

int main() {
    srand(time(nullptr));

    int arr[] = {8, 3, 7, 1, 9, 2, 6};
    int l = 0, r = 6;
    int n = 3; 

    int pivot_index = select_pivot(arr, l, r, n);

    cout << "Índice seleccionado: " << pivot_index << "\n";
    cout << "Valor del pivote: " << arr[pivot_index] << "\n";

    return 0;
}
