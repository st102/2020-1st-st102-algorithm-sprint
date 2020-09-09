import java.util.*;

public class Kata {
    public static String highAndLow(String numbers) {
        String[] tmp = numbers.split(" ");
        int[] result = new int[tmp.length];

        for (int i = 0; i < result.length; i++) {
            result[i] = Integer.parseInt(tmp[i]);
        }
        Arrays.sort(result);
        return Integer.toString(result[result.length - 1]) + " " + Integer.toString(result[0]);
    }
}