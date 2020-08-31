package Cote_Package;

public class DRoot {
    public static int digital_root(int n) {
        int output = 0;

        while(true) {
            if (n < 10) {
                output += n;
                break;
            }
            output += n % 10;
            n = n / 10;
        }
        if (output >= 10)
            output = digital_root(output);

        return output;
    }
}