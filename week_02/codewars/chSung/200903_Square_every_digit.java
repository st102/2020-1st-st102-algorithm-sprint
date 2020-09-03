public class SquareDigit {

    public int squareDigits(int num) {
        String square_num = "";

        while (num != 0) {
            int digit = num % 10;
            square_num = digit * digit + square_num;
            num /= 10;
        }

        return Integer.parseInt(square_num);
    }

}