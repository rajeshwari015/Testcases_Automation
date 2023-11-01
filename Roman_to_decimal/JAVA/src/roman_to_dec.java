public class roman_to_dec {
    public int romanToDecimal(String roman) {
        if (roman == null || roman.length() == 0) {
            throw new IllegalArgumentException("Invalid Roman numeral: " + roman);
        }

        int decimal = 0;
        int prevValue = 0;

        for (int i = roman.length() - 1; i >= 0; i--) {
            char currentChar = roman.charAt(i);
            int currentValue = getValue(currentChar);

            if (currentValue < prevValue) {
                decimal -= currentValue;
            } else {
                decimal += currentValue;
            }

            prevValue = currentValue;
        }

        return decimal;
    }

    private int getValue(char romanDigit) {
        switch (romanDigit) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                throw new IllegalArgumentException("Invalid Roman digit: " + romanDigit);
        }
    }

}