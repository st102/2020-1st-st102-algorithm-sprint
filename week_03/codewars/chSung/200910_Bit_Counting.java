public class BitCounting {

    public static int countBits(int number){
        String tmp_s = Integer.toBinaryString(number);
        return  tmp_s.length() - tmp_s.replace("1", "").length();
    }

}