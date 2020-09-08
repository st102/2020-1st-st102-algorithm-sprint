import java.util.Arrays;

public class Kata {
    public static int findShort(String s) {
        return Arrays.stream(s.split(" "))
                     .mapToInt(i -> i.length())
                     .min()
                     .getAsInt();

    }
}

