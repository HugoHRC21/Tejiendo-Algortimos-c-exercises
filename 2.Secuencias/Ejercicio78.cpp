#include<iostream>
#include<string>
#include <tpl_snode.H>
using namespace Aleph;
using namespace std;


struct Termino {
    int coef;
    size_t pot;

    Termino(int c = 0, size_t p = 0) : coef(c), pot(p) {}

    bool operator<(const Termino & otro) const {
        return pot > otro.pot; 
    }
};


class Polinomio {
private:
    Snode<Termino> * head; 
    size_t n;              

    void insertar_ordenado(int coef, size_t pot) {
        if (coef == 0)
            return;

        Snode<Termino> * nuevo = new Snode<Termino>(Termino(coef, pot));

        if (!head || pot > head->get_data().pot) {
            nuevo->get_next() = head;
            head = nuevo;
            n++;
            return;
        }

         Snode<Termino> * actual = head;
        while (actual->get_next() && actual->get_next()->get_data().pot > pot)
            actual = actual->get_next();

        if (actual->get_next() && actual->get_next()->get_data().pot == pot) {
            actual->get_next()->get_data().coef += coef;
            if (actual->get_next()->get_data().coef == 0) {
                Snode<Termino> * temp = actual->remove_next();
                delete temp;
                n--;
            }
            delete nuevo;
        } else {
            nuevo->get_next() = actual->get_next();
            actual->get_next() = nuevo;
            n++;
        }
    }

public:
   
    Polinomio() : head(nullptr), n(0) {}

  
    Polinomio(const int & coef, const size_t & pot) : head(nullptr), n(0) {
        if (coef != 0)
            insertar_ordenado(coef, pot);
    }

    ~Polinomio() {
        while (head != nullptr) {
            Snode<Termino> * temp = head;
            head = head->get_next();
            delete temp;
        }
    }


    Polinomio & operator += (const Polinomio & otro) {
        for (Snode<Termino> * actual = otro.head; actual != nullptr; actual = actual->get_next()) {
            insertar_ordenado(actual->get_data().coef, actual->get_data().pot);
        }
        return *this;
    }

    Polinomio operator + (const Polinomio & otro) const {
        Polinomio resultado(*this);
        resultado += otro;
        return resultado;
    }

    const size_t & size() const {
        return n;
    }

    size_t get_power(const size_t & i) const {
        Snode<Termino> * actual = head;
        for (size_t j = 0; j < i && actual; ++j)
            actual = actual->get_next();

        if (!actual)
            throw out_of_range("Índice fuera de rango");

        return actual->get_data().pot;
    }

    const int & get_coef(const size_t & i) const {
        Snode<Termino> * actual = head;
        for (size_t j = 0; j < i && actual; ++j)
            actual = actual->get_next();

        if (!actual)
            throw out_of_range("Índice fuera de rango");

        return actual->get_data().coef;
    }


    const size_t & get_degree() const {
        if (!head)
            throw logic_error("Polinomio vacío");

        return head->get_data().pot;
    }

    void print() const {
        Snode<Termino> * actual = head;
        while (actual) {
            cout << actual->get_data().coef << "x^" << actual->get_data().pot;
            if (actual->get_next())
                cout << " + ";
            actual = actual->get_next();
        }
        cout << "\n";
    }
};















































































}