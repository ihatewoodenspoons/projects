#!/bin/bash

# Set the source files
SRC_FILES="calculator.cpp"

# Set the output executable
OUTPUT="calculator"

# Compile the program
g++ -std=c++17 $SRC_FILES -o $OUTPUT 


# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "Run the program with ./$OUTPUT"

    # Ask the user if they want to run the program
    echo "Do you want to run the program? (y/n): "
    read choice

    # Ensuring no extra spaces are included in the input. Gives me PTSD from when I was dealing with similar issues building calculator.cpp's earlier versions.
    choice=$(echo "$choice" | tr -d '[:space:]')


    # Using case for matching "y" or "Y"
    case "$choice" in
        [yY])  # This matches both 'y' and 'Y'
            ./$OUTPUT
            ;;
        *)  # This matches anything else (including no input)
            echo "You can run it later with ./$OUTPUT."
            ;;
    esac
else
    echo "Build failed. Check the errors above."
fi
