class OctalToDecimal:

    def octalToDecimal(self, oct_num):
        decimal_num = int(oct_num, 8)
        return decimal_num

    def bubbleSort(self, octal_list):
        n = len(octal_list)

        for i in range(n):
            for j in range(0, n-i-1):
                if self.octalToDecimal(octal_list[j]) > self.octalToDecimal(octal_list[j+1]):
                    octal_list[j], octal_list[j+1] = octal_list[j+1], octal_list[j]

        return octal_list


# Example Usage
if __name__ == "__main__":
    # Example list of octal numbers
    octal_numbers = ["32", "17", "75", "13", "11"]

    # Creating an instance of the OctalToDecimal class
    converter = OctalToDecimal()

    # Sorting the list using bubble sort and converting to decimal representation
    sorted_decimal_numbers = converter.bubbleSort(octal_numbers)

    # Printing the sorted decimal numbers
    print("Sorted Decimal Numbers:")
    for num in sorted_decimal_numbers:
        print(converter.octalToDecimal(num))
