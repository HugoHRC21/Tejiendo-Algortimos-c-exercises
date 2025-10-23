
#include<iostream>
#include<string>
using namespace std;


const int MAX_ELEMENTOS = 10;


template<typename T>
class set{
    protected:
        T elementos[MAX_ELEMENTOS];
        int size;
    public:

    set() : size(0) {};

    size_t get_size(){
        return this->size;
    }

    void empty_set(){
        size = 0;
    }

    virtual void insert(T new_element){
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
        size_t tamano = conjunto.get_size();

        for(int i=0; i < size; i++){
            aux[i] = elementos[i];
        }
        
        int aux_size = size;
        empty_set();
                   
                
        for(int i=0; i < conjunto.get_size(); i++){
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

template<typename T>
class set_ordenado{
    private:
        T elementos[MAX_ELEMENTOS];
        int size;
    public:
        set_ordenado():size(0) {};

         size_t get_size() const{
            return this->size;
         }

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
                ordenar();
            } else {
                cout << "El conjunto esta lleno" << endl;
            }
        };

        void ordenar() {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (elementos[j] > elementos[j + 1]) {
                        T temp = elementos[j];
                        elementos[j] = elementos[j + 1];
                        elementos[j + 1] = temp;
                    }
                }
            }
        }

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
            size_t tamano = conjunto.get_size();
    
            for(int i=0; i < size; i++){
                aux[i] = elementos[i];
            }
            
            int aux_size = size;
            empty_set();
                       
                    
            for(int i=0; i < conjunto.get_size(); i++){
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

           ordenar();
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
    
        T seleccionar(int posicion){
            if(posicion < 0 and posicion >= size){
                return -1;
            }
           return elementos[posicion];
        }
    
        void split_pos(int posicion, set_ordenado<T>&l, set_ordenado<T>&r){
    
        for (int i = 0; i < size; i++) {
            if (i < posicion) {
                l.insert(elementos[i]); 
            } else {
                r.insert(elementos[i]); 
            }
        }
    }

};



int main(){
    set_ordenado<int> nuevobox, nuevoBox2, nuevobox3; 

    nuevobox.insert(4);
    nuevobox.insert(23);
    nuevobox.insert(3);
    nuevobox.insert(4);
    nuevobox.insert(15);
    nuevobox.insert(1);
    nuevobox.insert(7);

    // cout << "Elementos del nuevoBox: " << endl;
    // for(int i=0; i < nuevobox.get_size(); i++){
    //     cout << nuevobox.seleccionar(i) << endl;
    // }   cout << endl;

    nuevobox.split_pos(4, nuevoBox2, nuevobox3);

    // cout << "Elementos del nuevoBox: " << endl;
    // for(int i=0; i < nuevobox.get_size(); i++){
    //     cout << nuevobox.seleccionar(i) << endl;
    // }   cout << endl;


    for (int i{0}; i < nuevoBox2.get_size(); i++)
        cout << nuevoBox2.seleccionar(i) << " ";

    cout << "\n";

    
    for (int i{0}; i < nuevobox3.get_size(); i++)
        cout << nuevobox3.seleccionar(i) << " ";

    cout << "\n";
    return 0;
};