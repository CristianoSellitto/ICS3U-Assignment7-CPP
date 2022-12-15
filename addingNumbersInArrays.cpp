// Copyright Cristiano 2022
//
// Created by Cristiano Sellitto
// Created in December 2022
// A program that adds all of the numbers in
// an array and prints it back to the user

#include <iostream>
#include <string>
#include <array>

template <size_t length>
int AddNumbersInArrays(std::array<int, length> array, int numberOfLoops) {
    int sum = 0;

    for (int counter = 0; counter < numberOfLoops; counter++) {
        sum += array[counter];
    }

    return sum;
}

template <size_t length>
std::string FormatAddingArrayText(
    std::array<int, length> array,
    int numberOfLoops) {
    std::string equationText = "";

    for (int counter = 0; counter < numberOfLoops; counter++) {
        if (counter == numberOfLoops - 1) {
            equationText += std::to_string(array[counter]) + " = ";
        } else {
            equationText += std::to_string(array[counter]) + " + ";
        }
    }

    return equationText;
}

int main() {
    // Adds all of the numbers in an array and prints it back to the user

    int numberOfLoopsInteger = 0;
    int finalAnswer;
    std::string numberOfLoopsText;
    std::string fullEquationText;

    // Set the number of loops if it is a valid integer
    while (true) {
        try {
            std::cout << "Enter the amount of numbers";
            std::cout << "you want in the array (max = 20): ";
            std::cin >> numberOfLoopsText;
            std::cout << std::endl;
            numberOfLoopsInteger = stoi(numberOfLoopsText);
            if (numberOfLoopsInteger <= 20) {
                break;
            } else {
                std::cout << "You did not enter a valid integer.";
                std::cout << std::endl;
                std::cout << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "You did not enter a valid integer.";
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    // Append the inputted number to the array if it is a valid integer
    std::array<int, 20> numberArray;
    for (int counter = 0; counter < numberOfLoopsInteger; counter++) {
        try {
            float numberValue;
            std::string numberText;

            std::cout << "Number of inputs left: ";
            std::cout << numberOfLoopsInteger - counter;
            std::cout << std::endl;
            std::cout << "Enter a number: ";
            std::cin >> numberText;
            numberValue = stof(numberText);
            // For formatting integers
            if (stoi(numberText) % 1 == 0) {
                numberValue = stoi(numberText);
            }
            numberArray[counter] = numberValue;
            std::cout << std::endl;
        } catch (std::invalid_argument) {
            std::cout << "You did not enter a valid number.";
            std::cout << std::endl;
        }
    }
    // Write the full equation and calculate the answer
    finalAnswer = AddNumbersInArrays(numberArray, numberOfLoopsInteger);
    fullEquationText = FormatAddingArrayText(numberArray, numberOfLoopsInteger);
    // Print the full equation and the final answer as a string
    std::cout << fullEquationText << finalAnswer;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Done." << std::endl;
    }
