public class Solution {

    public int solution(int number) {
        int sum = 0;

        for (int i = 1; i * 3 < number; i++) {
            sum += i * 3;
        }
        for (int i = 1; i * 5 < number; i++) {
            if ((i * 5) % 15 == 0) {
                continue;
            }
            sum += i * 5;
        }

        return sum;
    }
}
