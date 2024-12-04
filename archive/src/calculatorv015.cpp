#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

 

int main() {
    // Declaring variables
    double num1, num2, num3, result;
    string operation;
    char answer;
    int angleType, trigOperation, tempint;

    cout << "Basic Terminal Calculator v0.15, macOS build. ";
    cout << "Cleared Display.";
    system("clear");

    while (true) {
        // First Number
        cout << "\nEnter first number:";
        cin >> num1;

        // Second Number
        cout << "\nEnter second number:";
        cin >> num2;

        // Third Number
        cout << "\nEnter third number used for square roots, trigonometric operations:";
        cin >> num3;

        // Clearing input buffer for newline issues
        cin.ignore();

        // Asking for operation
        cout << "What operation? Should be +, -, *, /, ^, trig, or root (square root). Type 'help' for help.:";
        getline(cin, operation);

        if (operation == "help") {
            cout << "\n- HELP GUIDE:";
            cout << "\n- Enter numbers for operations like addition, subtraction, multiplication, or division.";
            cout << "\n- Operations available: +, -, *, /, ^ (power), root (square root).";
            cout << "\n- For square roots, enter the number for which you want the square root or trig. operations (third number).";
            cout << "\n- For all operations, excluding square roots, the first and second numbers are used.";
            cout << "\n- Enter 'help' at any time to show this guide.";
            cout << "\n- Returning you to the beginning.";
            continue;
        }
        // Checking the Operation

        // *** |||| TRIG IS BUGGY. |||| ***

        if (operation == "trig") {
            cout << "Use degrees or radians? (1 or 2):";
            cin >> angleType;
            cin.ignore();
            cout << angleType;

            cout << "Enter a trigonometric function (sine, cosine, tangent). (1, 2, 3)";
            cin >> tempint;
            cin.ignore();
            cout << tempint;

            if (tempint == 1) {
                cin.ignore();
                trigOperation = 1;
            } else if (tempint == 2) {
                cin.ignore();
                trigOperation = 2;
            }
            cout << "You entered: " << angleType << " for angle type and " << trigOperation << " for function." << endl; // Debugging

            if (trigOperation == 1 || tempint == 1) {
                if (angleType == 1) {
                    result = sin(num3 * M_PI / 180 );
                } else if (angleType == 2) {
                    result = sin(num3); // Uses radians by default.
                } else {
                    cout << "Invalid input for angle type or input error. Returning to beginning.";
                    continue;
                }
            } else if (trigOperation == 2 || tempint == 2) {
                if (angleType == 1) {
                    result = cos(num3 * M_PI / 180);
                } else if (angleType == 2) {
                    result = cos(num3); // Not even gonna bother adding anymore comments. I'm so freaking done it's 2 am
                } else {
                    cout << "Invalid input for angle type. Returning to beginning.";
                    continue;
                }
            } else if (trigOperation == 3 || tempint == 3) {
                if (angleType == 1) {
                    result = tan(num3 * M_PI / 180);
                } else if (angleType == 2) {
                    result = tan(num3);
                } else {
                    cout << "Invalid input for angle type or input error. Returning to beginning.";
                    continue;
                }
            } else {
                cout << "Invalid trigonometric function. Returning to beginning.";
                continue; // Error handling
            }
        }
        if (operation == "root") {
            if (num3 < 0) { // Square roots, error handling code
                cout << "\n Complex numbers are not supported yet. Returning to beginning";
                continue;
            }
            result = sqrt(num3);
        } else if (operation == "^") {
            result = pow(num1, num2); // Powers
        } else if (operation == "+") {
            result = num1 + num2; // Addition
        } else if (operation == "-") {
            result = num1 - num2; // Subtraction
        } else if (operation == "*") {
            result = num1 * num2; // Multiplication
        } else if (operation == "/") {
            if (num2 == 0) {
                cout << "\nDividing by zero is not allowed. Returning to beginning";
                continue; // Dividing by zero handler code
            } else {
                result = num1 / num2; // Division
            }
        } else {
            cout << "\nInvalid operation. Returning to beginning";
            continue; // More error handling
        }

        system("clear");
        cout << "\nResult is: " << result;
        
        cout << "\n Do you want to perform another calculation? (y/n)";
        cin >> answer;
        if (answer != 'y' && answer != 'Y') {
            break;
        } else {
            system("clear");
        }
        
    }
    cout << "System returned error code 0.";
    return 0;
}



