package Cote_Package;
import java.util.stream.Stream;

public class SquareDigit {
    public int squareDigits(int n) {
        String output = "";
        int[] digits = Stream.of(String.valueOf(n).split("")).mapToInt(Integer::parseInt).toArray();

        for (int i = 0; i < digits.length; i++) {
            output += String.valueOf(digits[i] * digits[i]);
        }

        return Integer.parseInt(output);
    }
}