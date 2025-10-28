#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int seleccionar_aleatorio(int arr[], int n){
        int aleatorio = rand() % n;
        return arr[aleatorio];
    };

int seleccionarAleatorioConCentinela(int arr[]) {
    int count = 0;
    int suma = 0;

    while (arr[count] != -1) { 
        suma += arr[count];
        count++;
    }
    int indiceAleatorio = rand() % count;
    return arr[indiceAleatorio];
}
        
struct nodo{
    int dato;
    nodo* next;
};

class list{
    public:
    nodo* cabeza;
    
    list() : cabeza(nullptr) {};

    void agregar(int valor){
        nodo* nuevo_nodo = new nodo{valor ,cabeza};
        cabeza = nuevo_nodo;
    }

    int seleccionar_aleatorio(){
        nodo* actual = cabeza;
        int resultado = 0;
        int contador = 0;

        while(actual != nullptr){
            if(rand() % (++contador) == 0){
                resultado = actual->dato;
            }
            actual = actual->next;
        }

        return resultado;
    }
};

int main() {
    srand(static_cast<int>(time(0)));
    int arr[] = {10, 20, 30, 40, 50, 45, 32, 543, 235 ,234, 252, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int elemento = seleccionar_aleatorio(arr, n);
    cout << "Elemento seleccionado: " << elemento << endl;

    int elemento2 = seleccionarAleatorioConCentinela(arr);
    cout << "Elemento seleccionado (Con valor centinela): " << elemento << endl;

    return 0;
}
