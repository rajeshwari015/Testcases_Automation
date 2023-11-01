class RomanToDecimal:
    roman_numerals = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    def romanToDecimal(self, roman_numeral):
        decimal_num = 0
        prev_value = 0

        for numeral in reversed(roman_numeral):
            value = self.roman_numerals[numeral]
            if value < prev_value:
                decimal_num -= value
            else:
                decimal_num += value
            prev_value = value

        return decimal_num

# Example Usage
if __name__ == "__main__":
    # Example list of Roman numerals
    roman_numerals = ["XII", "IX", "XXI", "IV", "XLIV"]

    # Creating an instance of the RomanToDecimal class
    converter = RomanToDecimal()

    # Converting Roman numerals to decimal representation
    decimal_numbers = [converter.romanToDecimal(num) for num in roman_numerals]

    # Printing the converted decimal numbers
    print("Converted Decimal Numbers:")
    for num in decimal_numbers:
        print(num)
