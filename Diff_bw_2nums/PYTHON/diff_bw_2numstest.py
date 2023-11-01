from diff_bw_2nums import DifferenceBetweenTwoNumbers

class DifferenceBetweenTwoNumbersTest:

    def test(self, num1, num2, expected_difference):
        calculator = DifferenceBetweenTwoNumbers()
        result = calculator.calculateDifference(num1, num2)
        return result == expected_difference

# Example Usage
if __name__ == "__main__":
    # Test cases for absolute difference calculation
    test_cases = [
        {"input1": 15, "input2": 7, "expected_output": 8},
        {"input1": 30, "input2": 45, "expected_output": 15},
        {"input1": 10, "input2": 10, "expected_output": 0},
        {"input1": 5, "input2": 20, "expected_output": 15},
        {"input1": 100, "input2": 75, "expected_output": 25}
    ]

    # Creating an instance of the DifferenceBetweenTwoNumbersTest class
    tester = DifferenceBetweenTwoNumbersTest()

    # Running the test cases
    for test_case in test_cases:
        input1 = test_case["input1"]
        input2 = test_case["input2"]
        expected_difference = test_case["expected_output"]
        test_result = tester.test(input1, input2, expected_difference)

        if test_result:
            print(f"Test Passed for inputs {input1} and {input2}. Difference: {expected_difference}")
        else:
            print(f"Test Failed for inputs {input1} and {input2}. Expected: {expected_difference}")
