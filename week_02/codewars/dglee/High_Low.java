package Cote_Package;
import java.util.stream.*;
public class High_Low {
    public static String highAndLow(String numbers) {
        String output = "";
        int[] digits = Stream.of(numbers.split(" ")).mapToInt(Integer::parseInt).toArray();
        int min = digits[0];
        int max = digits[0];

        for (int i = 1; i < digits.length; i++) {
            if (min > digits[i])
                min = digits[i];

            if (max < digits[i])
                max = digits[i];
        }
        return String.format("%d %d", max, min);
    }
}