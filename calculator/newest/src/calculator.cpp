#include <iostream> // Pf course it's here.
#include <cmath> // because this is a calculator
#include <chrono> // sleep stuff
#include <thread> // sleep stuff 2
#include <limits> // For numeric_limits
#include <iomanip> // setprecision 
#include <algorithm> // For std::transform - basically just some stuff to make the code case-insensitive
#include <cctype> // For std::tolower - basically also some stuff to make the code case-insensitive
#include <string> // To make life 7000 times easier when it comes to strings

std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
            [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

int main() {
    double num1, num2, num3, result;
    std::string operation, trigOperation, angleType, category;
    char answer;

    std::cout << "Basic Terminal Calculator v0.19, Unix-like build." << std::endl;
    std::cout << "Cleared Display." << std::endl;
    system("clear");
    std::cout << std::scientific << std::setprecision(16) << std::defaultfloat; // for uhh cool decimal stuff
    while (true) {
        
        // Currently, this code has been left unused. It will be fully implemented in v0.19.
        std::cout << "Select a category:" << std::endl;
        std::cout << "1. Basic Operations (+, -, *, /, sqrt, ^)" << std::endl;
        std::cout << "2. Trigonometric Operations (sin, cos, tan)" << std::endl;
        std::cout << "3. Advanced Operations (factorial, absolute value)" << std::endl;
        std::cout << "4. Experimental Operations (Solve for variable)" << std::endl;
        std::cout << "5. Help Screen" << std::endl;
        std::cout << "6. Release Notes" << std::endl;
        std::cout << "Category selected: ";
        std::cin >> category;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears buffer
        category = toLowerCase(category);

        // This is gonna be part of the TO-DO, bleh
        if (category == "release notes" || category == "6" || category == "notes" || category == "release") {
            std::cout << "\n- Release notes for v0.19:";
            std::cout << "\n- Added a feature, a creature feature, where you can set the category. It was added to make the UI look less garbage.";
            std::cout << "\n- okay uhhm im not adding anything else as this is literally just a copy-paste from the help menu";
            std::cout << "\n- For square roots, enter the number for which you want the square root or trig. operations (third number).";
            std::cout << "\n- For all operations, excluding square roots, the first and second numbers are used.";
            std::cout << "\n- jhadslkjshsjkfdlhdfsakjlhf";
            std::cout << "\n- Returning you to the beginning.";
            continue;
        } else if (category == "help" || category == "5") {
            std::cout << "\n- HELP GUIDE:";
            std::cout << "\n- ";
            std::cout << "\n- Operations available: +, -, *, /, ^ (powers), sqrt (square root), and trig (trigonometric) operations.";
            std::cout << "\n- For square roots, enter the number for which you want the square root or trig. operations (third number).";
            std::cout << "\n- For all operations, excluding square roots, the first and second numbers are used.";
            std::cout << "\n- Enter 'help' at any time to show this guide.";
            std::cout << "\n- Returning you to the beginning.";
            continue;
        }

        // Operation logic
        if (operation == "sqrt") {
            if (num3 < 0) {
                std::cout << "\nComplex numbers are not supported yet. Returning to beginning.";
                continue;
            }
            result = std::sqrt(num3);
        } else if (operation == "trig"){
            std::cout << "Use degrees or radians? (deg or rad):";
            std::cin >> angleType;
            std::cin.ignore();
            std::cout << angleType;

            std::cout << "Enter a trigonometric function (sine, cosine, tangent). (sin, cos, tan)";
            std::cin >> trigOperation;
            std::cin.ignore();
            std::cout << trigOperation;

            // Running the function for the trigonometric functions like sin(var) uses radians by default.
            if (trigOperation == "sin") {
                if (angleType == "deg") {
                    result = std::sin(num3 * M_PI / 180 );
                } else if (angleType == "rad") {
                    result = std::sin(num3); 
                } else {
                    std::cout << "Invalid input for angle type/input error. Returning to beginning.";
                    continue;
                }
            } else if (trigOperation == "cos") {
                if (angleType == "deg") {
                    result = std::cos(num3 * M_PI / 180);
                } else if (angleType == "rad") {
                    result = std::cos(num3); 
                } else {
                std::cout << "Invalid input for angle type/input error. Returning to beginning.";
                    continue;
                }
            } else if (trigOperation == "tan") {
                if (angleType == "deg") {
                    result = std::tan(num3 * M_PI / 180);
                } else if (angleType == "rad") {
                    result = std::tan(num3);
                } else {
                    std::cout << "Invalid input for angle type/input error. Returning to beginning.";
                    continue;
                }
            } else {
                std::cout << "Invalid trigonometric function. Returning to beginning.";
                continue; // Error handling
            }
        } else if (operation == "^") {
            result = std::pow(num1, num2);
        } else if (operation == "+") {
            result = num1 + num2;
        } else if (operation == "-") {
            result = num1 - num2;
        } else if (operation == "*") {
            result = num1 * num2;
        } else if (operation == "/") {
            if (num2 == 0) {
                std::cout << "\nDividing by zero is not allowed. Returning to beginning.";
                continue;
            }
            result = num1 / num2;
        } else {
            std::cout << "\nInvalid operation. Returning to beginning.";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            continue;
        }

        // Display results
        system("clear");
        std::cout << "\n 1 after the number means it was ignored.";
        std::cout << "\nFirst number was: " << num1;
        std::cout << "\nSecond number was: " << num2;
        std::cout << "\nThird number was: " << num3;
        std::cout << "\nResult is: " << result;

        // Continue or exit
        std::cout << "\nDo you want to perform another calculation? (y/n):";
        std::cin >> answer;
        if (answer != 'y' && answer != 'Y') {
            
            break;
        } else {
            std::cout << "\nClear variables? (y/n)";
            std::cin >> answer;
            if (answer != 'n' && answer != 'N') {
                std::cout << "Clearing variables...";
                result = 0;
                num1 = 0;
                num2 = 0;
                num3 = 0;
                operation = "null";
                trigOperation = "null";
                angleType = "null";
                answer = '0';
            }
        }
    }

    std::cout << "System returned error code 0.";
    system("clear");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;
}
