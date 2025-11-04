#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;


bool esOperador(string c) {
    return c == "+" || c == "-" || c == "*" || c == "/";
}


int aplicarOperacion(string op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b;
    return 0;
}


int evaluarSufija(string expr) {
    stack<int> pila;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (!esOperador(token)) {
            pila.push(stoi(token)); 
        } else {
            int b = pila.top(); pila.pop();
            int a = pila.top(); pila.pop();
            int resultado = aplicarOperacion(token, a, b);
            pila.push(resultado);
        }
    }

    return pila.top(); 
}

int main() {
    string expresion;

    cout << "Ingrese una expresion sufija (ej: 2 3 + 4 *): ";
    getline(cin, expresion);

    int resultado = evaluarSufija(expresion);
    cout << "Resultado: " << resultado << endl;

    return 0;
}
