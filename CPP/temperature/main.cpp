#include <iostream>

int main() {
    std::cout << "TEMPERATURE CONVERSION PROGRAM" << "\n\n";
    std::cout << "1. Celsius to fahrenheit\n2. Fahrenheit to celsius";
    int select = 0;
    
    float celsius = 0;
    float fahrenheit = 0;

    std::cin >> select;

    switch(select) {
    case -1:
        return 1;
    case 1:
        std::cin >> celsius;
        fahrenheit = (celsius * (9.0/5.0)) + 32;
        std::cout << "\n" << fahrenheit;
        break;
    case 2:
        std::cin >> fahrenheit;
        celsius = (fahrenheit - 32) * 5.0/9.0;
        std::cout << "\n" << celsius;
        break;
    default:
        break;
    }

    return 0;

}
