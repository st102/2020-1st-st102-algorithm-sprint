package Cote_Package;
import java.util.stream.IntStream;
public class Equal_Sides {
    public static int findEvenIndex(int[] arr) {
        int left = 0;
        int right = IntStream.of(arr).sum();

        for (int i = 0; i < arr.length; i++) {
            right -= arr[i];

            if (left == right)
                return i;

            left += arr[i];
        }
        return -1;
    }
}