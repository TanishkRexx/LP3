#include <iostream>
using namespace std;

// Non-Recursive Function
void fibonacciNonRecursive(int n) {
    int a = 0, b = 1, c;

    cout << "Non-Recursive Fibonacci: ";

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

// Recursive Function
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) +
           fibonacciRecursive(n - 2);
}

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    fibonacciNonRecursive(n);

    cout << "\nRecursive Fibonacci: ";

    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }

    return 0;
}