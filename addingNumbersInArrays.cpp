// Copyright Cristiano 2022
//
// Created by Cristiano Sellitto
// Created in December 2022
// A program that adds all of the numbers in
// an array and prints it back to the user

#include <iostream>
#include <string>

int main() {
    // Adds all of the numbers in an array and prints it back to the user

    int numberOfLoopsInteger;
    int finalAnswer = 0;
    std::string numberOfLoopsText;
    std::string fullEquationText = "";

    // Set the number of loops if it is a valid integer
    while (true) {
        try {
            std::cout << "Enter the amount of numbers you want in the array: ";
            std::cin >> numberOfLoopsText;
            std::cout << std::endl;
            numberOfLoopsInteger = stoi(numberOfLoopsText);
            break;
        } catch (std::invalid_argument) {
            std::cout << "You did not enter a valid integer.";
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    // Append the inputted number to the array if it is a valid integer
    int numberArray[512];
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
    for (int counter = 0; counter < numberOfLoopsInteger; counter++) {
        if (counter == numberOfLoopsInteger - 1) {
            fullEquationText = (
                fullEquationText +
                std::to_string(numberArray[counter]) +
                " = ");
        } else {
            fullEquationText = (
                fullEquationText +
                std::to_string(numberArray[counter]) +
                " + ");
        }
        finalAnswer = finalAnswer + numberArray[counter];
    }
    // Print the full equation and the final answer as a string
    std::cout << fullEquationText << finalAnswer;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Done." << std::endl;
    }
