public class oct_to_dectest {
    boolean test(String input, int expectedOutput) {
        if (input == null) {
            throw new IllegalArgumentException("Input octal string cannot be null");
        }
        
        oct_to_dec octToDec = new oct_to_dec();
        int result = octToDec.convertToDecimal(input);
        return result == expectedOutput;
    }
}