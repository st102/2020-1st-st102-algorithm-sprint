package Cote_Week01;

public class multiples {

    public static int getMultiples(int num) {
        int sum = 0;

        if (num <= 0)
            return 0;

        for (int i = 0; i < num; i++) {
            if (i % 3 == 0 || i % 5 == 0)
                sum += i;
        }
        return sum;
    }
}
