#include "../include/countingnumbers_test.hpp"
#include "../include/countingnumbers.hpp"
#include <iostream>
#include <vector>

bool CountingNumbersTester::testCountDigits(int number, int expectedCount) {
    CountingNumbers counter;
    int result = counter.countDigits(number);
    return result == expectedCount;
}

