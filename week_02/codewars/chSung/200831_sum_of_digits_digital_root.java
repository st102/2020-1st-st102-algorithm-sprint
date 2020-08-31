public class DRoot {
    public static int digital_root(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum < 10) {
            return sum;
        } else {
            return digital_root(sum);
        }
    }
}
