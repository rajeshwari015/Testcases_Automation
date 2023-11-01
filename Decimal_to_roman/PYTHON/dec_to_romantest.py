from dec_to_roman import DecimalToRoman

class DecimalToRomanTest:

    def test(self, input_decimal, expected_roman):
        converter = DecimalToRoman()
        result = converter.decimalToRoman(input_decimal)
        return result == expected_roman

# Example Usage
if __name__ == "__main__":
    # Test cases for decimal to Roman numeral conversion
    test_cases = [
        {"input": 13, "expected_output": "XIII"},
        {"input": 49, "expected_output": "XLIX"},
        {"input": 88, "expected_output": "LXXXVIII"},
        {"input": 124, "expected_output": "CXXIV"},
        {"input": 399, "expected_output": "CCCXCIX"}
    ]

    # Creating an instance of the DecimalToRomanTest class
    tester = DecimalToRomanTest()

    # Running the test cases
    for test_case in test_cases:
        input_decimal = test_case["input"]
        expected_roman = test_case["expected_output"]
        test_result = tester.test(input_decimal, expected_roman)

        if test_result:
            print(f"Test Passed for input '{input_decimal}'. Roman numeral: {expected_roman}")
        else:
            print(f"Test Failed for input '{input_decimal}'. Expected: {expected_roman}")
