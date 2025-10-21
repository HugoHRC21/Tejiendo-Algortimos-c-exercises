/*Amplíe el TAD hComplejo 5i para manejar coordenadas polares. Discuta dónde poner
la ampliación (en nuevos métodos, en una clase derivada, etcétera) */

//Complejo 5
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class NumberPreciso {
private:
    char signo;
    string entera;
    string decimal;

public:
    NumberPreciso(char s, string e, string d) : signo(s), entera(e), decimal(d) {}

    void sumar_y_resta(char ns, string ne, string nd) {
        string signoFinal;
        bool aux;
        if(signo == '+' && ns == '-' or signo == '-' && ns == '+'){
            signoFinal = '-';
            
            if (nd.length() < decimal.length()) {
                nd.append(decimal.length() - nd.length(), '0');
            } else if (decimal.length() < nd.length()) {
                decimal.append(nd.length() - decimal.length(), '0');
            }
    
            int acarreo = 0;
            string resultado_decimal;
            for (int i = decimal.length() - 1; i >= 0; i--) {
                int suma = (decimal[i] - '0') - (nd[i] - '0') + acarreo;
                resultado_decimal.push_back((suma % 10) + '0');
                acarreo = suma / 10;
            }
    
            if (acarreo > 0) {
                resultado_decimal.push_back(acarreo + '0');
            }
    
            reverse(resultado_decimal.begin(), resultado_decimal.end());
    
            if (ne.length() < entera.length()) {
                ne.insert(0, entera.length() - ne.length(), '0');
            } else if (entera.length() < ne.length()) {
                entera.insert(0, ne.length() - entera.length(), '0');
            }
    
            acarreo = 0;
            string resultado_entera;
            for (int i = entera.length() - 1; i >= 0; i--) {
                int suma = (entera[i] - '0') - (ne[i] - '0') + acarreo;
                resultado_entera.push_back((suma % 10) + '0');
                acarreo = suma / 10;
            }
    
            if (acarreo > 0) {
                resultado_entera.push_back(acarreo + '0');
            }
    
            reverse(resultado_entera.begin(), resultado_entera.end());
            cout << "Resultado: " << signoFinal << resultado_entera << "," << resultado_decimal << endl;

            } else {

            if (nd.length() < decimal.length()) {
                nd.append(decimal.length() - nd.length(), '0');
            } else if (decimal.length() < nd.length()) {
                decimal.append(nd.length() - decimal.length(), '0');
            }
    
            int acarreo = 0;
            string resultado_decimal;
            for (int i = decimal.length() - 1; i >= 0; i--) {
                int suma = (decimal[i] - '0') + (nd[i] - '0') + acarreo;
                resultado_decimal.push_back((suma % 10) + '0');
                acarreo = suma / 10;
            }
    
            if (acarreo > 0) {
                resultado_decimal.push_back(acarreo + '0');
            }
    
            reverse(resultado_decimal.begin(), resultado_decimal.end());
    
            if (ne.length() < entera.length()) {
                ne.insert(0, entera.length() - ne.length(), '0');
            } else if (entera.length() < ne.length()) {
                entera.insert(0, ne.length() - entera.length(), '0');
            }
    
            acarreo = 0;
            string resultado_entera;
            for (int i = entera.length() - 1; i >= 0; i--) {
                int suma = (entera[i] - '0') + (ne[i] - '0') + acarreo;
                resultado_entera.push_back((suma % 10) + '0');
                acarreo = suma / 10;
            }
    
            if (acarreo > 0) {
                resultado_entera.push_back(acarreo + '0');
            }
    
            if(signo == '+' && ns == '+') {signoFinal = '+';}
            if(signo == '-' && ns == '-') {signoFinal = '-';}

            reverse(resultado_entera.begin(), resultado_entera.end());
            cout << "Resultado: " << signoFinal << resultado_entera << "," << resultado_decimal << endl;
        }
    }


    void multipacion(char nuevo_signo, string nuevo_entero, string nuevo_decimal){
         int total_decimal = decimal.length() + nuevo_decimal.length();
         string resultado_decimal(total_decimal, '0');

         for (int i = nuevo_decimal.length() - 1; i >= 0; i--) {
             int acarreo = 0;
             string temp_resultado(total_decimal, '0');
             for (int j = decimal.length() - 1; j >= 0; j--) {
                 int producto = (nuevo_decimal[i] - '0') * (decimal[j] - '0') + acarreo;
                 temp_resultado[j + i + 1] = (producto % 10) + '0'; 
                 acarreo = producto / 10;
             }
             if (acarreo > 0) {
                 temp_resultado[i] = acarreo + '0';
             }
             resultado_decimal = sumar_cadenas(resultado_decimal, temp_resultado);
         }

         string resultado_entera = "0";
         for (int i = nuevo_entero.length() - 1; i >= 0; i--) {
             int acarreo = 0;
             string temp_resultado(entera.length() + nuevo_entero.length(), '0');
             for (int j = entera.length() - 1; j >= 0; j--) {
                 int producto = (nuevo_entero[i] - '0') * (entera[j] - '0') + acarreo;
                 temp_resultado[j + i + 1] = (producto % 10) + '0'; 
                 acarreo = producto / 10;
             }
             if (acarreo > 0) {
                 temp_resultado[i] = acarreo + '0';
             }
             resultado_entera = sumar_cadenas(resultado_entera, temp_resultado);
         }

         char resultado_signo = (signo == nuevo_signo) ? '+' : '-';
 
         cout << "Resultado: " << resultado_signo
              << resultado_entera << "," << resultado_decimal << endl;
     }
 
     string sumar_cadenas(string a, string b) {
         if (a.length() < b.length()) {
             a.insert(0, b.length() - a.length(), '0');
         } else if (b.length() < a.length()) {
             b.insert(0, a.length() - b.length(), '0');
         }
 
         string resultado;
         int acarreo = 0;
         for (int i = a.length() - 1; i >= 0; i--) {
             int suma = (a[i] - '0') + (b[i] - '0') + acarreo;
             resultado.push_back((suma % 10) + '0');
             acarreo = suma / 10;
         }
         if (acarreo > 0) {
             resultado.push_back(acarreo + '0');
         }
         reverse(resultado.begin(), resultado.end());
         return resultado;
     }

};



int main() {
    NumberPreciso numero1('+', "2", "303338");
            numero1.multipacion('-', "2", "1011");

    return 0;
}
