#include "../include/diff_bw_2nums.hpp"
#include "../include/diff_bw_2numstest.hpp"
#include <iostream>

bool DiffBetweenTwoNumbersTest::test(int num1, int num2, int expectedDifference) {
    DiffBetweenTwoNumbers diffCalculator;
    int result = diffCalculator.calculateDifference(num1, num2);
    return result == expectedDifference;
}