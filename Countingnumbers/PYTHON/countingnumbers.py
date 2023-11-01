class CountingNumbers:

    def countDigits(self, number):
        # Convert the number to a string and calculate the length of the string
        num_str = str(number)
        num_of_digits = len(num_str)
        return num_of_digits

# Example Usage
if __name__ == "__main__":
    # Example numbers
    numbers = [123, 4567, 78901, 23456789, 1]

    # Creating an instance of the CountingNumbers class
    counter = CountingNumbers()

    # Counting the number of digits for each number
    for num in numbers:
        num_of_digits = counter.countDigits(num)
        print(f"Number: {num}, Number of Digits: {num_of_digits}")
