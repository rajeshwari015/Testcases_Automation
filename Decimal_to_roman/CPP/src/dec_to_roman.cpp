#include "../include/dec_to_roman.hpp"
#include <vector>
#include <string>

std::string DecimalToRoman::intToRoman(int num) {
    // Define symbols for Roman numerals and their corresponding values
    std::vector<std::pair<int, std::string>> romanSymbols = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string romanNumeral = "";
    
    // Iterate through the symbols and convert the number to Roman numerals
    for (const auto& symbol : romanSymbols) {
        int value = symbol.first;
        const std::string& romanSymbol = symbol.second;
        
        while (num >= value) {
            romanNumeral += romanSymbol;
            num -= value;
        }
    }

    return romanNumeral;
}
