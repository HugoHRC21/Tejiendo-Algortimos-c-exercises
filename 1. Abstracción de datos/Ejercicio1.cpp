
/*Diseñe e implante un TAD que represente números en punto flotante y en el cual se
especique la precisión, es decir, el tamaño de la mantisa y del exponente.*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class floating_point_number
{
private:
    int decimal;
    int entera;
    char signo;
    
public:
    floating_point_number(int e, int m, char s) : decimal(e), entera(m), signo(s) {}

    void mostrar(){

        if(signo == '-'){
        cout << signo;
        } 
        cout << entera <<"." << setw(2) << setfill('0') << decimal << endl;
    }
};

int main(){
    floating_point_number punto1(1,3,'-');

    punto1.mostrar();

    return 0;


}

 
