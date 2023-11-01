
#include "../include/roman_to_dec.hpp"
#include "../include/roman_to_dectest.hpp"
#include <iostream>
#include <vector>

bool RomanToDecimalTester::testRomanToDecimal(std::string roman, int expectedDecimal) {
    RomanToDecimal converter;
    int result = converter.romanToDecimal(roman);
    return result == expectedDecimal;
}

