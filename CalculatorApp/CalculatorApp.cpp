#include <iostream>
#include <vector>
#include <cmath>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

void plotLinearFunction(double slope, double intercept) {
    std::vector<double> x(100);
    std::vector<double> y(100);

    for (int i = 0; i < 100; ++i) {
        x[i] = i;
        y[i] = slope * x[i] + intercept;
    }

    plt::plot(x, y);
    plt::title("Linear Function: y = " + std::to_string(slope) + "x + " + std::to_string(intercept));
    plt::xlabel("x");
    plt::ylabel("y");
    plt::show();
}

void plotQuadraticFunction(double a, double b, double c) {
    std::vector<double> x(100);
    std::vector<double> y(100);

    for (int i = 0; i < 100; ++i) {
        x[i] = i - 50;
        y[i] = a * x[i] * x[i] + b * x[i] + c;
    }

    plt::plot(x, y);
    plt::title("Quadratic Function: y = " + std::to_string(a) + "x^2 + " + std::to_string(b) + "x + " + std::to_string(c));
    plt::xlabel("x");
    plt::ylabel("y");
    plt::show();
}

void graphFunctions() {
    std::cout << "Choose the type of function to graph:\n";
    std::cout << "1. Linear Function (y = mx + b)\n";
    std::cout << "2. Quadratic Function (y = ax^2 + bx + c)\n";
    
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        double slope, intercept;
        std::cout << "Enter slope (m): ";
        std::cin >> slope;
        std::cout << "Enter intercept (b): ";
        std::cin >> intercept;
        plotLinearFunction(slope, intercept);
    } else if (choice == 2) {
        double a, b, c;
        std::cout << "Enter a: ";
        std::cin >> a;
        std::cout << "Enter b: ";
        std::cin >> b;
        std::cout << "Enter c: ";
        std::cin >> c;
        plotQuadraticFunction(a, b, c);
    } else {
        std::cout << "Invalid choice." << std::endl;
    }
}

void basicCalculator() {
    char operation;
    double num1, num2;

    std::cout << "Enter your first number: ";
    std::cin >> num1;
    std::cout << "Enter an operator type (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Enter your second number: ";
    std::cin >> num2;

    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0)
                std::cout << "Result: " << num1 / num2 << std::endl;
            else
                std::cout << "Error: Division by zero." << std::endl;
            break;
        default:
            std::cout << "Error: Invalid operator." << std::endl;
    }
}

int main() {
    int choice;
    std::cout << "Select Your Calculator Type:\n";
    std::cout << "1. Basic Calculator\n";
    std::cout << "2. Scientific Calculator\n";
    std::cin >> choice;

    if (choice == 1) {
        basicCalculator();
    } else if (choice == 2) {
        graphFunctions();
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}