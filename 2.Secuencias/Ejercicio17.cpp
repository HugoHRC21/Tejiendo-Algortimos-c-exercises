#include<iostream>
#include<string>

using namespace std;

int main(){
    int m;
    const int n = 9;
    char Arreglo[n] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    cout << "ingrese el numero de rotaciones: "<< endl;
    cin >> m;
    char aux[n];
    for(int i(0); i < n; i++){
        aux[i] = Arreglo[(i + m) % n];
        cout << aux[i] << endl;
    }
    return 0;
};