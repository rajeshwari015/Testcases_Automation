public class oct_to_dec {
    public int convertToDecimal(String octal) {
        // Check if octal string is null
        if (octal == null) {
            throw new IllegalArgumentException("Input octal string cannot be null");
        }

        // Convert octal to decimal
        int decimal = 0;
        int n = octal.length();
        for (int i = 0; i < n; i++) {
            char digit = octal.charAt(i);
            int digitValue;
            if (digit >= '0' && digit <= '7') {
                digitValue = digit - '0';
            } else {
                // Invalid octal digit
                throw new IllegalArgumentException("Invalid octal digit: " + digit);
            }
            decimal = decimal * 8 + digitValue;
        }
        return decimal;
    }
}
