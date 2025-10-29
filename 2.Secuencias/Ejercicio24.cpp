#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
int select(T a[], size_t n, int i) {
    if (i < 0 || i >= n) {
        throw out_of_range("Index out of range");
    }

    int count;
    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(a[j] < a[i]){
                count++;
                continue;
            }
        }
        if (count == i) return a[i];
    }
    return 0;
}


int main() {
    int arr[] = {7, 2, 1, 6, 8, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int i = 2;

    try {
        int index = select(arr, n, i);
        cout << "El índice del " << (i + 1) << "er menor elemento es: " << index << endl;
    } catch (const out_of_range& e) {
        cerr << e.what() << endl;
    }

    return 0;
}