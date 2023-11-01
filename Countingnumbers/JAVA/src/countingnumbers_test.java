public class countingnumbers_test {
    
    boolean test(int number, int expectedCount) {
        countingnumbers countingNumbers = new countingnumbers();
        int result = countingNumbers.countDigits(number);
        return result == expectedCount;
    }
}