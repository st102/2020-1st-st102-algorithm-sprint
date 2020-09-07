package Cote_Package;
import java.util.stream.*;
import java.util.Arrays;
public class High_Low {
    public static String highAndLow(String numbers) {
        int[] digits = Stream.of(numbers.split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(digits);

        return String.format("%d %d", digits[digits.length - 1], digits[0]);
    }
}
