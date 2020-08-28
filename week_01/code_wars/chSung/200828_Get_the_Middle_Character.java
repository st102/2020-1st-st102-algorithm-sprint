class Kata {
    public static String getMiddle(String word) {
        String middle_c;
        int length = word.length();

        if (length % 2 == 1) {
            middle_c = String.valueOf(word.charAt(length / 2));
        } else {
            middle_c = String.valueOf(word.charAt(length / 2 - 1));
            middle_c += String.valueOf(word.charAt(length / 2));
        }

        return middle_c;

    }
}