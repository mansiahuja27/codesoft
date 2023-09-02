#include <iostream>
using namespace std;

int main() {
    double num1, num2, answer;
    string operation;  

    
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Enter the operation (add, subtract, multiply, divide): ";
    cin >> operation;

    
    for (char &c : operation) {
        c = tolower(c);
    }

    if (operation == "add") {
        answer = num1 + num2;
        cout << "Result: " << answer << endl;
    } else if (operation == "subtract") {
        answer = num1 - num2;
        cout << "Result: " << answer << endl;
    } else if (operation == "multiply") {
        answer = num1 * num2;
        cout << "Result: " << answer << endl;
    } else if (operation == "divide") {
        if (num2 != 0) {
            answer = num1 / num2;
            cout << "Result: " << answer << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Error: Invalid operation." << endl;
    }

    return 0;
}
