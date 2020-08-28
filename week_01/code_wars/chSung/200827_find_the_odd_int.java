public class FindOdd {
    public static int findIt(int[] a) {

        int i;
        for (i = 0; i < a.length; i++) {
            int num = 0;
            for (int j = 0; j < a.length; j++) {
                if (a[i] == a[j]) num++;
            }
            if (num % 2 != 0) return a[i];
        }

        int odd = a[i];

        return odd;

    }
}