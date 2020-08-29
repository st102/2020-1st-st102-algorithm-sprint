package Cote_Package;

public class Disemvowel_Trolls {

    public static String disemvowel(String str) {
        String output = "";

        for (char c: str.toCharArray()) {
            switch (c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    continue;
            }
            output = output.concat(String.valueOf(c));
        }

        return output;
    }
}