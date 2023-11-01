#include "../include/dec_to_roman.hpp"
#include "../include/dec_to_romantest.hpp"
#include <iostream>
#include <vector>

bool DecimalToRomanTester::testIntToRoman(int num, std::string expectedRomanNumeral) {
    DecimalToRoman converter;
    std::string result = converter.intToRoman(num);
    return result == expectedRomanNumeral;
}