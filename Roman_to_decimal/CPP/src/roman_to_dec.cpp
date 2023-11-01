#include "../include/roman_to_dec.hpp"
#include <unordered_map>

int RomanToDecimal::romanToDecimal(std::string roman) {
    std::unordered_map<char, int> romanNumerals = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int decimalNumber = 0;
    int prevValue = 0;

    for (int i = roman.length() - 1; i >= 0; --i) {
        int currentValue = romanNumerals[roman[i]];

        if (currentValue < prevValue) {
            decimalNumber -= currentValue;
        } else {
            decimalNumber += currentValue;
        }

        prevValue = currentValue;
    }

    return decimalNumber;
}
