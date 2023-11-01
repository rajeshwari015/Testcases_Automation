from oct_to_dec import OctalToDecimal

class OctalToDecimalTest:

    def test(self, input_octal, expected_decimal):
        converter = OctalToDecimal()
        result = converter.octalToDecimal(input_octal)
        return result == expected_decimal


# Example Usage
if __name__ == "__main__":
    # Test cases for octal to decimal conversion
    test_cases = [
        {"input": "32", "expected_output": 26},
        {"input": "17", "expected_output": 15},
        {"input": "75", "expected_output": 61},
        {"input": "13", "expected_output": 11},
        {"input": "11", "expected_output": 9}
    ]

    # Creating an instance of the OctalToDecimalTest class
    tester = OctalToDecimalTest()

    # Running the test cases
    for test_case in test_cases:
        input_octal = test_case["input"]
        expected_decimal = test_case["expected_output"]
        test_result = tester.test(input_octal, expected_decimal)

        if test_result:
            print(f"Test Passed for input '{input_octal}'. Decimal value: {expected_decimal}")
        else:
            print(f"Test Failed for input '{input_octal}'. Expected: {expected_decimal}")
