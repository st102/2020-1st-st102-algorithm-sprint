public class Kata {
    public static String createPhoneNumber(int[] numbers) {
        String phone_num = "";
        for (int i = 0; i < numbers.length; i++) {
            if (i == 0) phone_num += '(';
            else if (i == 3) phone_num += ") ";
            else if (i == 6) phone_num += '-';

            phone_num += numbers[i];
        }
        return phone_num;
    }
}