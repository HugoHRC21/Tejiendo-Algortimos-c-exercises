/*Dado un conjunto S definido por el tipo Set<T, Compare>, explique cómo conocer el
elemento correspondiente a la mediana en el sentido estadístico.*/

#include <iostream>
#include <string>
#include <set>
#include <iterator>
using namespace std;



template<typename T, typename Compare>
T buscarMediana(const set<T, Compare>& S){
    int tamano = S.size();
    if(tamano == 0){
        throw invalid_argument("Set vacio");
    }

    auto aux = S.begin();
    advance(aux, tamano/2);
    if (tamano % 2 == 1) {
        return *aux; 
    } else {
        T izquierda = *prev(aux);
        T derecha = *aux;
        return (izquierda + derecha)/2;
    }

}

int main(){
    set<int> box = {23,13,1,1,2,3,4,5,6,7,8,9,9,42};

    // 1,1,2,3,4,5,6,7,8,9,13,23,42
    try {
        cout << "La mediana es: " << buscarMediana(box) << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}