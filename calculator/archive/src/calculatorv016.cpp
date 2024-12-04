
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits> // For numeric_limits

using namespace std;

int main() {
    double num1, num2, num3, result;
    string operation, trigOperation, angleType;
    char answer;

    cout << "Basic Terminal Calculator v0.16, macOS build. ";
    cout << "Cleared Display.";
    system("clear");

    while (true) {
        // First Number
        cout << "\nEnter first number:";
        cin >> num1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        // Second Number
        cout << "\nEnter second number:";
        cin >> num2;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        // Third Number
        cout << "\nEnter third number used for square roots, trigonometric operations:";
        cin >> num3;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        // Asking for operation
        cout << "What operation? Should be +, -, *, /, ^, trig, or root (square root). Type 'help' for help.:";
        getline(cin, operation); // Use getline for full line input

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

       

        // Additional operations
        if (operation == "root") {
            if (num3 < 0) {
                cout << "\nComplex numbers are not supported yet. Returning to beginning.";
                continue;
            }
            result = sqrt(num3);
        } else if (operation == "trig"){
            cout << "Use degrees or radians? (deg or rad):";
    cin >> angleType;
    cin.ignore();
    cout << angleType;

    cout << "Enter a trigonometric function (sine, cosine, tangent). (sin, cos, tan)";
    cin >> trigOperation;
    cin.ignore();
    cout << trigOperation;

     if (trigOperation == "sin") {
        if (angleType == "deg") {
            result = sin(num3 * M_PI / 180 );
        } else if (angleType == "rad") {
            result = sin(num3); // Uses radians by default.
        } else {
            cout << "Invalid input for angle type or input error. Returning to beginning.";
            continue;
        }
    } else if (trigOperation == "cos") {
        if (angleType == "deg") {
            result = cos(num3 * M_PI / 180);
        } else if (angleType == "rad") {
            result = cos(num3); // Uses radians by default.
        } else {
            cout << "Invalid input for angle type. Returning to beginning.";
            continue;
        }
    } else if (trigOperation == "tan") {
        if (angleType == "deg") {
            result = tan(num3 * M_PI / 180);
        } else if (angleType == "rad") {
            result = tan(num3);
        } else {
            cout << "Invalid input for angle type or input error. Returning to beginning.";
            continue;
            }
    } else {
        cout << "Invalid trigonometric function. Returning to beginning.";
        continue; // Error handling
    }
        } else if (operation == "^") {
            result = pow(num1, num2);
        } else if (operation == "+") {
            result = num1 + num2;
        } else if (operation == "-") {
            result = num1 - num2;
        } else if (operation == "*") {
            result = num1 * num2;
        } else if (operation == "/") {
            if (num2 == 0) {
                cout << "\nDividing by zero is not allowed. Returning to beginning.";
                continue;
            }
            result = num1 / num2;
        } else {
            cout << "\nInvalid operation. Returning to beginning.";
            continue;
        }

        // Display result
        system("clear");
        cout << "\nFirst number was: " << num1;
        cout << "\nSecond number was: " << num2;
        cout << "\nThird number was: " << num3;
        cout << "\nResult is: " << result;

        // Continue or exit
        cout << "\nDo you want to perform another calculation? (y/n):";
        cin >> answer;
        if (answer != 'y' && answer != 'Y') break;

        system("clear");
    }

    cout << "System returned error code 0.";
    return 0;
}
