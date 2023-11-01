#include "../include/oct_to_dec.hpp"
#include "../include/oct_to_dectest.hpp"
#include <iostream>
#include <vector>


bool OctToDecimalTester::testOctToDecimal(std::string octal, int expectedDecimal) {
    OctToDecimal converter;
    int result = converter.octToDecimal(octal);
    return result == expectedDecimal;
}

// This file contains the test logic without the main method.
