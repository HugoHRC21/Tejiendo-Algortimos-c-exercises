/*Dado un conjunto S definido por el tipo Set<T, Compare>, explique cómo se programaría, en función de las primitivas de hConjunto fundamental 18i, la rutina:
        template <class __Set>
        __Set extraer(__Set & set, int i, int j);
la cual extrae de S, y retorna en un nuevo conjunto, todos los elementos que están entre
las posiciones i y j respectivamente. Después de la operación, S contiene los elementos
entre los rangos [0..i − 1] y [j + 1..n − 1], donde n = |S|.*/

#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <iterator>
#include <stdexcept>
#include <vector>
using namespace std;


// template <typename T, class Compare>
// struct Set {
//     void insert(const T & key);
//     T * search(const T & key);  
//     void remove(const T & key);
//     size_t size() const;
//     void swap(Set<T, Compare> & set);
//     void join(Set<T, Compare> * set);
//     void split(const T& key, Set<T, Compare> *& l, Set<T, Compare> *& r);
//     const int position(const T& key) const;
//     T * select(const int pos);
//     void split_pos(const int & pos, Set<T, Compare> *& l, Set<T, Compare> *& r);
// };

// template <class __Set>

// __Set extraer(__Set & set, int i, int j){
//     auto validate = [&](){
//         return (i < 0 || j < 0 || j < i || j >= set.size());
//     };
//     if(not validate()){
//         throw invalid_argument("invalid indexes");
//     }

//     vector<int>Nuevo_conjunto;

//     for(int indice = i; i <= j; indice++){
//         Nuevo_conjunto.push_back(set[indice]);
//     }

//     set.erase(set.begin() + i, set.begin() + j + 1);

//     return Nuevo_conjunto;

// }
int main(){
    // -4 -3 -2 -1 4 5 6 7
    unordered_set<int> S{ 4, -1, 5, -2, 6, -3, 7, -4};
    int l, r;

    cin >> l >> r;

    auto p = S.begin();
    auto q = S.begin();
    advance(p, 0);
    advance(q, r + 1);
    unordered_set<int> Q;

    for (; p != q; ++p)
        Q.insert(*p);

    for (auto p: Q)
        cout << p << " ";

    cout << "\n";

    return 0;

}
