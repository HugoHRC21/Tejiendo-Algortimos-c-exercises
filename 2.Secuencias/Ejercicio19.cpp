#include <iostream>
#include <stdexcept>

using namespace std;

unsigned long long fibonacci(int i)
{
    if (i < 0)
        throw invalid_argument("El índice debe ser no negativo.");

    if (i == 0) return 0;
    if (i == 1) return 1;

    unsigned long long a = 0, b = 1, fib = 0;

    for (int n = 2; n <= i; ++n){
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib;
}

int main()
{
    int i;
    cout << "Ingrese el índice i: ";
    cin >> i;

    try {
        cout << "Fibonacci(" << i << ") = " << fibonacci(i) << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
