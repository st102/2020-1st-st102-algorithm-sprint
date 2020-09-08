package Cote_Package;

public class Shortest_Word {
    public static int findShort(String s) {
        String[] array = s.split(" ");
        int short_length = array[0].length();
        
        for (int i = 1; i < array.length; i++)
            short_length = (array[i].length() > short_length) ? short_length : array[i].length();

        return short_length;
    }
    
    
}