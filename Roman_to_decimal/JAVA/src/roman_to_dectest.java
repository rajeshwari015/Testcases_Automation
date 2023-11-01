public class roman_to_dectest {
    boolean test(String romanNumeral, int expectedDecimal) {
        roman_to_dec romanToDecimal = new roman_to_dec();
        int result = romanToDecimal.romanToDecimal(romanNumeral);
        return result == expectedDecimal;
    }
}
