class DifferenceBetweenTwoNumbers:

    def calculateDifference(self, num1, num2):
        absolute_difference = (num1 - num2)
        return absolute_difference

# Example Usage
if __name__ == "__main__":
    # Example numbers
    num1 = 15
    num2 = 7

    # Creating an instance of the DifferenceBetweenTwoNumbers class
    calculator = DifferenceBetweenTwoNumbers()

    # Calculating the difference between the two numbers
    difference = calculator.calculateDifference(num1, num2)

    # Printing the absolute difference
    print(f"Absolute Difference Between {num1} and {num2}: {difference}")
