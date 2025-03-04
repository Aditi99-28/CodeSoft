#include <iostream>

using namespace std;

// Function to perform arithmetic operations
double calculate(double num1, double num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else {
                cout << "Error: Division by zero is not allowed." << endl;
                return 0;
            }
        default:
            cout << "Error: Invalid operator." << endl;
            return 0;
    }
}

int main() {
    double num1, num2;
    char op;
    
    // Taking user input
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    
    // Performing calculation
    double result = calculate(num1, num2, op);
    
    // Display result
    cout << "Result: " << result << endl;
    
    return 0;
}

