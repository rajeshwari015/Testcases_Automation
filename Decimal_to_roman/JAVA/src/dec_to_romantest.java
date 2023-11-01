public class dec_to_romantest {
  
  boolean test(int input, String output) {
    dec_to_roman decToRoman = new dec_to_roman();
    String result = decToRoman.intToRoman(input);
    return result.equals(output);
  }
}