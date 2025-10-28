#include<iostream>
#include<string>
#include<stdexcept>
#include<DynArray.h>


using namespace std;


int main(){

    const int MAX_ELEMENTOS = 10; 
    int* elementos = new int[MAX_ELEMENTOS]; 
    size_t size = 0; 

   
    cout << "Ingrese los elementos del arreglo (ingrese -1 para terminar):" << endl;
    while (size < MAX_ELEMENTOS) {
        int new_element;
        cin >> new_element;
        if (new_element == -1) break; 

      
        if (size >= MAX_ELEMENTOS) {
            cout << "El conjunto está lleno." << endl;
            return 0;
        }

        
        bool aux = false;
        for (int i = 0; i < size; i++) {
            if (elementos[i] == new_element) {
                aux = true; 
                break;
            }
        }
        if (!aux) {
            elementos[size] = new_element; 
            size++;
        } else {
            cout << "El valor ya se encuentra en el arreglo." << endl;
        }
    }


    int* aux = new int[MAX_ELEMENTOS];
    size_t auxSize = 0; 

    for (size_t i = 0; i < size; i++) {
        bool found = false;
        for (size_t j = 0; j < auxSize; j++) {
            if (elementos[i] == aux[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            aux[auxSize++] = elementos[i]; 
        }
    }


    for (size_t i = 0; i < auxSize; i++) {
        elementos[i] = aux[i]; 
    }

    size = auxSize; 
    delete[] aux; 


    cout << "Elementos sin duplicados:" << endl;
    for (size_t i = 0; i < size; i++) {
        cout << elementos[i] << " "; 
    }
    cout << endl;


    delete[] elementos;

    return 0; 
};
