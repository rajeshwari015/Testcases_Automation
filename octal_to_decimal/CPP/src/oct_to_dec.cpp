#include "../include/oct_to_dec.hpp"
#include <cmath>

int OctToDecimal::octToDecimal(std::string octal) {
    int decimalNumber = 0;
    int octalDigit, position = 0;
    
    // Iterate through the octal string in reverse order
    for (int i = octal.length() - 1; i >= 0; --i) {
        // Convert character to integer
        octalDigit = octal[i] - '0';
        
        // Validate octal digit
        if (octalDigit < 0 || octalDigit > 7) {
            // Handle invalid input
            // You can throw an exception, return an error code, or handle it as appropriate for your application
        }
        
        // Convert octal digit to decimal and add it to the result
        decimalNumber += octalDigit * static_cast<int>(pow(8, position));
        ++position;
    }
    
    return decimalNumber;
}
