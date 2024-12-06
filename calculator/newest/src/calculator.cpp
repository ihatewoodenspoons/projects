#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include <limits> // For numeric_limits

int main() {
    int varsWasIgnored;
    double num1, num2, num3, result;
    std::string operation, trigOperation, angleType;
    char answer;

    std::cout << "Basic Terminal Calculator v0.18, *nix build. ";
    std::cout << "Cleared Display.";
    system("clear");

    while (true) {
        // First Number
        std::cout << "\nEnter first number:";
        std::cin >> num1;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer

        // Second Number
        std::cout << "\nEnter second number:";
        std::cin >> num2;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer

        // Third Number
        std::cout << "\nEnter third number used for square roots, trigonometric operations:";
        std::cin >> num3;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer

        // Asking for operation
        std::cout << "What operation? Should be +, -, *, /, ^, trig, or sqrt. Type 'help' for help.:";
        std::getline(std::cin, operation); // Use getline for full line input

        if (operation == "help") {
            std::cout << "\n- HELP GUIDE:";
            std::cout << "\n- Enter numbers for operations like addition, subtraction, multiplication, or division.";
            std::cout << "\n- Operations available: +, -, *, /, ^ (power), root (square root).";
            std::cout << "\n- For square roots, enter the number for which you want the square root or trig. operations (third number).";
            std::cout << "\n- For all operations, excluding square roots, the first and second numbers are used.";
            std::cout << "\n- Enter 'help' at any time to show this guide.";
            std::cout << "\n- Returning you to the beginning.";
            continue;
        }

        // Additional operations
        if (operation == "sqrt") {
            if (num3 < 0) {
                std::cout << "\nComplex numbers are not supported yet. Returning to beginning.";
                varsWasIgnored = 0 + 1;
                continue;
            }
            result = std::sqrt(num3);
        } else if (operation == "trig"){
            varsWasIgnored = 0 + 1;
            std::cout << "Use degrees or radians? (deg or rad):";
            std::cin >> angleType;
            std::cin.ignore();
            std::cout << angleType;

            std::cout << "Enter a trigonometric function (sine, cosine, tangent). (sin, cos, tan)";
            std::cin >> trigOperation;
            std::cin.ignore();
            std::cout << trigOperation;

            if (trigOperation == "sin") {
                if (angleType == "deg") {
                    result = std::sin(num3 * M_PI / 180 );
                } else if (angleType == "rad") {
                    result = std::sin(num3); // Uses radians by default.
                } else {
                    std::cout << "Invalid input for angle type or input error. Returning to beginning.";
                    continue;
                }
            } else if (trigOperation == "cos") {
                if (angleType == "deg") {
                    result = std::cos(num3 * M_PI / 180);
                } else if (angleType == "rad") {
                    result = std::cos(num3); // Uses radians by default.
                } else {
                    std::cout << "Invalid input for angle type or input error. Returning to beginning.";
                    continue;
                }
            } else if (trigOperation == "tan") {
                if (angleType == "deg") {
                    result = std::tan(num3 * M_PI / 180);
                } else if (angleType == "rad") {
                    result = std::tan(num3);
                } else {
                    std::cout << "Invalid input for angle type or input error. Returning to beginning.";
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
        std::cout << "\nFirst number was: " << num1 << " " << varsWasIgnored;  
        std::cout << "\nSecond number was: " << num2 << " " << varsWasIgnored;
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
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                result = 0;
                std::cout << "\n Cleared variable 'result'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                num1 = 0;
                std::cout << "\n Cleared variable 'num1'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                num2 = 0;
                std::cout << "\n Cleared variable 'num2'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                num3 = 0;
                std::cout << "\n Cleared variable 'num3'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                operation = "null";
                std::cout << "\n Cleared string 'operation'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                trigOperation = "null";
                std::cout << "\n Cleared string 'trigOperation'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                angleType = "null";
                std::cout << "\n Cleared string 'angleType'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                answer = '0';
                std::cout << "\n Cleared char 'answer'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                varsWasIgnored = 0;
                std::cout << "\n Cleared variable 'varsWasIgnored'.";
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                std::cin.ignore();
                system("clear");

            }
        }

        system("clear");
    }

    std::cout << "System returned error code 0.";
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;
}
