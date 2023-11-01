from roman_to_decimal import RomanToDecimal

class RomanToDecimalTest:

    def test(self, input_roman, expected_decimal):
        converter = RomanToDecimal()
        result = converter.romanToDecimal(input_roman)
        return result == expected_decimal


# Example Usage
if __name__ == "__main__":
    # Test cases for Roman to decimal conversion
    test_cases = [
        {"input": "XII", "expected_output": 12},
        {"input": "IX", "expected_output": 9},
        {"input": "XXI", "expected_output": 21},
        {"input": "IV", "expected_output": 4},
        {"input": "XLIV", "expected_output": 44}
    ]

    # Creating an instance of the RomanToDecimalTest class
    tester = RomanToDecimalTest()

    # Running the test cases
    for test_case in test_cases:
        input_roman = test_case["input"]
        expected_decimal = test_case["expected_output"]
        test_result = tester.test(input_roman, expected_decimal)

        if test_result:
            print(f"Test Passed for input '{input_roman}'. Decimal value: {expected_decimal}")
        else:
            print(f"Test Failed for input '{input_roman}'. Expected: {expected_decimal}")
