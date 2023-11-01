class DecimalToRoman:

    def decimalToRoman(self, decimal_num):
        roman_numerals = {
            1: 'I', 4: 'IV', 5: 'V', 9: 'IX', 10: 'X',
            40: 'XL', 50: 'L', 90: 'XC', 100: 'C',
            400: 'CD', 500: 'D', 900: 'CM', 1000: 'M'
        }

        roman_numeral = ''
        for value, numeral in sorted(roman_numerals.items(), key=lambda x: x[0], reverse=True):
            while decimal_num >= value:
                roman_numeral += numeral
                decimal_num -= value

        return roman_numeral

# Example Usage
if __name__ == "__main__":
    # Example decimal numbers
    decimal_numbers = [13, 49, 88, 124, 399]

    # Creating an instance of the DecimalToRoman class
    converter = DecimalToRoman()

    # Converting decimal numbers to Roman numerals
    print("Decimal to Roman Numerals:")
    for num in decimal_numbers:
        roman_numeral = converter.decimalToRoman(num)
        print(f"Decimal: {num} -> Roman: {roman_numeral}")
