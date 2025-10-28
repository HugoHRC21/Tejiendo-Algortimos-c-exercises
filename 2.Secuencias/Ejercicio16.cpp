#include<iostream>
#include<string>
#include<stdexcept>
#include<DynArray.h>
#include<ctime>

using namespace std;

int main(){
    long n;
    srand(time(nullptr));
    cout << "Ingrese el valor de n: " << endl;
    cin >> n;

    long faltante = rand() % n;
    long sumaActual = 0;
    cout << "Elemento faltante a ser deducido: " << faltante << "\n";
    for (int i{0}; i < n; i++) sumaActual += ( i == faltante ? 0 : i );


    cout << "El elemento faltante es: " << ((n*(n-1)/2) - sumaActual) << endl;  
    return 0;
}