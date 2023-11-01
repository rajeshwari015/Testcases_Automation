from countingnumbers import CountingNumbers

class CountingNumbersTest:

    def test(self, input_number, expected_digits):
        counter = CountingNumbers()
        result = counter.countDigits(input_number)
        return result == expected_digits

# Example Usage
if __name__ == "__main__":
    # Test cases for counting numbers
    test_cases = [
        {"input": 123, "expected_output": 3},
        {"input": 4567, "expected_output": 4},
        {"input": 78901, "expected_output": 5},
        {"input": 23456789, "expected_output": 8},
        {"input": 1, "expected_output": 1}
    ]

    # Creating an instance of the CountingNumbersTest class
    tester = CountingNumbersTest()

    # Running the test cases
    for test_case in test_cases:
        input_number = test_case["input"]
        expected_digits = test_case["expected_output"]
        test_result = tester.test(input_number, expected_digits)

        if test_result:
            print(f"Test Passed for input '{input_number}'. Number of Digits: {expected_digits}")
        else:
            print(f"Test Failed for input '{input_number}'. Expected: {expected_digits}")
