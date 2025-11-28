// 59. Diseñe un algoritmo que determine si una expresión algebraica tiene sus paréntesis
// balanceados (+).
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool are_parentheses_balanced(const string& expr) {
    stack<char> st;

    for (char c : expr) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) {
                return false; 
            }
            st.pop();
        }
    }

    return st.empty(); 
}

int main() {
    string expr1 = "(a+b) * (c-d)";
    string expr2 = "((a+b))";
    string expr3 = "((a+b)";

    cout << expr1 << " → " << (are_parentheses_balanced(expr1) ? "Balanceado" : "No balanceado") << endl;
    cout << expr2 << " → " << (are_parentheses_balanced(expr2) ? "Balanceado" : "No balanceado") << endl;
    cout << expr3 << " → " << (are_parentheses_balanced(expr3) ? "Balanceado" : "No balanceado") << endl;

    return 0;
}
