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

unsigned long long factorial(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 1; i <= n; ++i) {
        if (result > std::numeric_limits<unsigned long long>::max() / i) {
            std::cerr << "Overflow error: Cannot compute factorial, as the value is too large.";
            return 0;
        }
        result *= i;
    }
    return result;
}



int main() {
    double num1, num2, num3, result;
    unsigned long long int num4longint;
    std::string operation, trigOperation, angleType, category, subCategory;
    char answer;

    std::cout << "Basic Terminal Calculator v0.19, Unix-like build." << std::endl;
    std::cout << "Cleared Display." << std::endl;
    system("clear");
    std::cout << std::scientific << std::setprecision(16) << std::defaultfloat; // for uhh cool decimal stuff
    while (true) {
        
        // Currently, this code has been left unused. It will be fully implemented in v0.19.
        std::cout << "Select a category:" << std::endl;
        std::cout << "1. Basic Operations (+, -, *, /, sqrt, ^, factorial, abs.)" << std::endl;
        std::cout << "2. Trigonometric Operations (sin, cos, tan)" << std::endl;
        std::cout << "3. Conversion Operations" << std::endl;
        std::cout << "4. Experimental Operations (Solve for variable)" << std::endl;
        std::cout << "4. Help Screen" << std::endl;
        std::cout << "5. Release Notes" << std::endl;
        std::cout << std::endl;
        std::cout << "Category selected: ";
        std::cin >> category;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears buffer
        category = toLowerCase(category);

        // This is gonna be part of the TO-DO, bleh
        if (category == "release notes" || category == "5" || category == "notes" || category == "release") {
            std::cout << "- Release notes for v0.19:" << std::endl;
            std::cout << "- Added a feature where you can set the category. It was added to make the UI look less garbage." << std::endl;
            std::cout << "- HELP GUIDE is now outdated. Will be updated soon." << std::endl;
            std::cout << "- Returning to beginning." << std::endl;
            continue;
        } else if (category == "help" || category == "4") {
            std::cout << "- HELP GUIDE:" << std::endl;
            std::cout << "- THIS GUIDE IS OUTDATED, BUILT FOR CALCULATOR V0.18" << std::endl;
            std::cout << "- Operations available: +, -, *, /, ^ (powers), sqrt (square root), and trig (trigonometric) operations." << std::endl;
            std::cout << "- For square roots, enter the number for which you want the square root or trig. operations (third number)." << std::endl;
            std::cout << "- For all operations, excluding square roots, the first and second numbers are used."<< std::endl;
            std::cout << "- Enter 'help' at any time to show this guide." << std::endl;
            std::cout << "- Returning you to the beginning." << std::endl;
            continue;
            // Next up, get ready for the most unreadable mess ever!
        } else if (category == "basic" || category == "1") { 
            std::cout << "Clearing display.";
            system("clear");
            std::cout << "Input the first number: ";
            std::cin >> num1;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Input the second number: ";
            std::cin >> num2;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Input the third number: ";
            std::cin >> num3;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << std::endl << "Enter the operation's symbol from the list below: " << std::endl;
            std::cout << "1. Usual Operations (+, -, *, /, sqrt, ^ (power), cbrt (cube root))" << std::endl;
            std::cout << "2. Advanced Operations (abs (absolute value), n! (factorial))" << std::endl;
            std::cout << "3. Syntax Help" << std::endl;
            std::cout << std::endl;
            std::cout << "Entered: ";
            std::cin >> operation;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            operation = toLowerCase(operation);
            

            // Operation logic below
            if (operation == "+") {
                result = num1 + num2;
            } else if (operation == "-") {
                result = num1 - num2;
            } else if (operation == "*") {
                result = num1 * num2;
            } else if (operation == "/") {
                if (num2 == 0) {
                    std::cerr << "Dividing by zero is not allowed." << std::endl;
                } else {
                    result = num1 / num2;
                }
            } else if (operation == "sqrt" || operation == "sqroot" || operation == "square root") {
                if (num3 < 0) {
                    std::cerr << "Complex numbers are not yet supported." << std::endl;
                } else {
                    result = std::sqrt(num3);
                }
            } else if (operation == "^" || operation == "power" || operation == "exponent") {
                result = std::pow(num1, num2);
            } else if (operation == "abs" || operation == "absolute" || operation == "absolute value") {
                result = fabs(num3);
            } else if (operation == "fact" || operation == "factorial" || operation == "n!") {
                std::cout << "Note that this WILL have issues with floating-point values." << std::endl;
                std::cout << "For your sanity, the number has been rounded up to an integer." << std::endl;
                std::cout << "Or, it will be disposed of if the number is negative." << std::endl;
                if (num3 < 0) {
                    std::cerr << "Factorial could be negative, cannot proceed." << std::endl;
                    system("clear");
                    continue;
                } else {
                    num4longint = std::nearbyint(num3);
                    result = factorial(num4longint);
                }
            } else if (operation == "syntax help" || operation == "help" || operation == "syntax") {
                std::cout << "- SYNTAX HELP";
                std::cout << "- Numbers 1 and 2 are used for the operations that involve two numbers." << std::endl;
                std::cout << "- Examples: +, -, *, /, ^ (powers)" << std::endl;
                std::cout << "- Number 3 is used for things that only need one number." << std::endl;
                std::cout << "- Examples: sqrt, cbrt, abs. value, n!" << std::endl;
                continue;
            }
        } else if (category == "trigonometric" || category == "trig" || category == "2") {
            std::cout << "Clearing display.";
            system("clear");
            std::cout << "Input the number used for the trignometric operation: ";
            std::cin >> num3;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << std::endl << "Enter the operation'from the list below: " << std::endl;
            std::cout << "1. Usual Operations (+, -, *, /, sqrt, ^ (power), cbrt (cube root))" << std::endl;
            std::cout << "2. Sine (sin)" << std::endl;
            std::cout << std::endl;
            std::cout << "Entered: ";
            std::cin >> operation;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            operation = toLowerCase(operation);
        }

        // Display results
        system("clear");
        std::cout << "- First number was: " << num1 << std::endl;
        std::cout << "- Second number was: " << num2 << std::endl;
        std::cout << "- Third number was: " << num3 << std::endl;
        std::cout << "- Operation done was: " << operation << std::endl;
        if (category == "trigonometric" || category == "trig" || category == "2") { 
            std::cout << "- Operation done was: " << trigOperation << std::endl;
        } else {
            std::cout << "- Operation done was: " << operation << std::endl;
        }

        std::cout << "- Result is: " << result << std::endl;

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
    std::cout << "System returned error code 0." << std::endl;
    system("clear");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;
}
