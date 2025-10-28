#include<iostream>
#include<string>
#include<stdexcept>
#include<DynArray.h>


using namespace std;


int main(){

            const int MAX_ELEMENTOS = 10;
            int* elementos = new int [MAX_ELEMENTOS];
            size_t size = 0;

            
            cout << "ingrese los 10 elementos del arreglo :" << endl;
            for(int i =0; i < MAX_ELEMENTOS; i++){
                int num;
                cin >> num;
                elementos[size++] = num;
            }

            int* aux = new int [size];
            size_t size2 = 0;


            
            for(int i = 0; i < size; i++){
                if(elementos[i] != elementos[i-1]){
                    aux[size2++]= elementos[i];
                }
            }

            for(int i = 0; i < size2; i++){
                elementos[i] = aux[i];
            }

            size = size2;
            delete [] aux;
       

            cout << "Elementos sin duplicados:" << endl;
            for (size_t i = 0; i < size; i++) {
                cout << elementos[i] << " "; 
            }
    cout << endl;



   
    return 0;


};
