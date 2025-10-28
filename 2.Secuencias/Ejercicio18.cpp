#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

unsigned long long fibonacci_helper(int i, vector<unsigned long long> &memo)
{
    if (memo[i] != (unsigned long long)-1)
        return memo[i];

    return memo[i] = fibonacci_helper(i - 1, memo) + fibonacci_helper(i - 2, memo);
}

unsigned long long fibonacci(int i)
{
    if (i < 0)
        throw invalid_argument("El índice debe ser no negativo.");

    vector<unsigned long long> memo(i + 1, -1);
    memo[0] = 0;
    if (i >= 1)
        memo[1] = 1;

    return fibonacci_helper(i, memo);
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