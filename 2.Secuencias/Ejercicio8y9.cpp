#include <iostream>
#include <string>

using namespace std;

template<typename T >
struct DynArray{

         T* data;
        int size;
        int capacidad;


        void resize(){
            capacidad *= 2;
            T* nuevaData = new T[capacidad];
            for(int i = 0; i < size; i++){
                nuevaData[i] = data[i]; 
            }
            delete[] data;
            data = nuevaData;
        }

         DynArray(int capacidad_inicial = 10) : size(0), capacidad(capacidad_inicial) {data = new T[capacidad];}


         void insertar_ordenado(const T& valor){
            if(size>=capacidad){
                resize();
            }

            int i = 0;
            while (i < size and data[i] < valor){
                i++;
            }

            for (int j = size; j > i; --j){
                data[j] = data[j -1];   
            }

            data[i] = valor;
            ++size;
         }


         void eliminar_ordenado(const T& valor){
            int i = 0;

            while(i < size and data[i] < valor){
                ++i;
            }

            if( i < size and data[i] == valor){
                for(int j = i; j < size -1; ++j){
                    data[j] = data[j+1];
                }
                --size;
            }
         }
};

int main(){

    DynArray<int> box(6);

    box.insertar_ordenado(3);
    box.insertar_ordenado(36);
    box.insertar_ordenado(23);
    box.insertar_ordenado(98);
    box.insertar_ordenado(7);

    cout << "Elementos: " << endl;
    for(int i = 0; i < box.size; i++){
        cout << i+1 << ". " << box.data[i] << endl;
    }
    cout << endl;

    box.eliminar_ordenado(23);

    cout << "Elementos con elemento eliminado: " << endl;
    for(int i = 0; i < box.size; i++){
        cout << i+1 << ". " << box.data[i] << endl;
    }

    return 0;
}
