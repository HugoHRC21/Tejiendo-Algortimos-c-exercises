
#include<iostream>
#include<string>
using namespace std;

const int MAX_ELEMENTOS = 10;

template<typename T>
struct set{
    
        T elementos[MAX_ELEMENTOS];
        int size;
    
        set() : size(0) {};

        size_t Get_size()const{
            return size;
        };

        void empty_set(){
            size = 0;
        }

        void insert(T new_element){
            if(size>= MAX_ELEMENTOS){
                cout << " EL conjunto esta lleno " << endl;
                return;
            }

            bool aux = false;
            for(int i = 0; i < size; i++){
                if(elementos[i] == new_element){
                    aux = true;
                    break;
                }
            }
            if(!aux){
                elementos[size] = new_element;
                size++;
            } else {
                cout << "El conjunto esta lleno" << endl;
            }
        };
     
        T* buscar(T elemento){
            for(int i=0; i < size; i++){
                if(elementos[i] == elemento){
                    return &elementos[i];
                    break;
                }
            }
                cout << "Elemento no encontrado" << endl;
                return nullptr;
        };
    
        void eliminar(T elemento){
            for(int i=0; i < size; i++){
                if(elementos[i] == elemento){
                    for(int j=i; j < size - 1; j++){
                        elementos[j] = elementos[j+1];
                    }
                    size--;
                    cout << "Elemento indicado fue eliminado" << endl;
                    return;
                }
            }

            cout << "Elemento indicado no encontrado para eliminar " << endl;
        };

        void swap(set<T>& conjunto){
            T* aux = new T[MAX_ELEMENTOS];
            size_t tamano = conjunto.Get_size();

            for(int i=0; i < size; i++){
                aux[i] = elementos[i];
            }
            
            int aux_size = size;
            empty_set();
                       
                    
            for(int i=0; i < conjunto.Get_size(); i++){
                size++;
                elementos[i] = conjunto.elementos[i];
            }
            conjunto.empty_set();

            for(int i=0; i < aux_size; i++){
                conjunto.size++;
                conjunto.elementos[i] = aux[i];
            }
            
            delete[] aux;

            cout << "Intercambio de Elementos entre conjunto realizados" << endl;
        };

        void join(set<T>& conjunto){
             for(int i=0; i < conjunto.size; i++){
                if (contains(conjunto.elementos[i])) continue;
                append(conjunto.elementos[i]);
            }
        }

        void append(T& element) {
            elementos[size] = element;
            size++;
        }

        bool contains(T& element) {
            for(int j=0; j < size; j++)
                if(elementos[j] == element) return true;
            return false;
        }

        int find(T& elem) {
            for (int i{0}; i < size; i++) {
                if (elem == elementos[i]) return i;
            }
            return -1;
        }

        set<T> split(T elemento){
            set<T> Nuevo;
            
            auto pos = find(elemento);
            
            size_t aux_size = size;
            for (int i{pos}; i < aux_size; i++)
            {
                Nuevo.append(elementos[i]);
                size--;
            }
            return Nuevo;
        }

        const int posicion(const T& elemento){
            for(int i=0; i < size; i++){
                if(elementos[i] == elemento){
                    return i;
                }
            }
            return -1;
        }

        T* seleccionar(int posicion){
                if(posicion < 0 and posicion >= size){
                    return nullptr;
                }
               return &elementos[posicion];
            }
        
        void split_pos(int posicion, set<T>&l, set<T>&r ){

            for (int i = 0; i < size; i++) {
                if (posicion < i) {
                    l.insert(elementos[i]); 
                } else {
                    r.insert(elementos[i]); 
                }
            }
        }
        
        
};

int main(){

    set<int> box1, box2, box3;
    box1.insert(1);
    box1.insert(2);
    box1.insert(3);
    box1.insert(4);
    box1.insert(5);
    box1.insert(6);
    box1.insert(7);

    cout << "Elementos del Box1: " << endl;

    for(int i=0; i < box1.Get_size(); i++){
        cout << box1.elementos[i] << endl;
    }
    cout << endl;

    box1.split_pos(3, box2, box3);

    cout << "Elementos del Box2: " << endl;

    for(int i=0; i < box2.Get_size(); i++){
        cout << box2.elementos[i] << endl;
    }
    cout << endl;

    cout << "Elementos del Box3: " << endl;

    for(int i=0; i < box2.Get_size(); i++){
        cout << box3.elementos[i] << endl;
    }
    cout << endl;



    // int* aux = box1.seleccionar(2);

    // cout << box1.posicion(90) << endl;
    // cout << *aux << endl;

    return 0;
};