/*Amplíe el TAD hComplejo 5i para manejar coordenadas polares. Discuta dónde poner
la ampliación (en nuevos métodos, en una clase derivada, etcétera) */

//Complejo 5
#include <iostream>
#include <cmath>

using namespace std;

// struct Complejo
// {
// Complejo(float r, float i);
// Complejo(const Complejo & c);
// float & obtenga_parte_real();
// float & obtenga_parte_imag();
// };

using polar = pair<float, float>;

class Complejo{
    private:
        float real;
        float imaginaria;
    public:
        Complejo(float r, float i) : real(r), imaginaria(i) {}

        Complejo(const Complejo & c) : real(c.real) , imaginaria(c.imaginaria) {}

        float get_Real(){
            return this->real;
        }
        float get_Imaginario(){
            return this->imaginaria;
        }

        polar get_polar() {
            return make_pair(
                sqrt(
                    pow(this -> real, 2) + pow(this -> imaginaria, 2)
                ),
                atan(this -> imaginaria / this -> real)
            );
        }
        

};


int main()
{
    return 0;
}