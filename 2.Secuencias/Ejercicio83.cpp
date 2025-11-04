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

int evaluarPrefija(string expr) {
    stack<int> pila;
    vector<string> tokens;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        tokens.push_back(token);
    }

    for (int i = tokens.size() - 1; i >= 0; i--) {
        string t = tokens[i];

        if (!esOperador(t)) {
            pila.push(stoi(t)); 
        } else {
            int a = pila.top(); pila.pop();
            int b = pila.top(); pila.pop();
            int resultado = aplicarOperacion(t, a, b);
            pila.push(resultado);
        }
    }

    return pila.top(); 
}

int main() {
    string expresion;

    cout << "Ingrese una expresion prefija (ej: * + 2 3 4): ";
    getline(cin, expresion);

    int resultado = evaluarPrefija(expresion);
    cout << "Resultado: " << resultado << endl;

    return 0;
}
