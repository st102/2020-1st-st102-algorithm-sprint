package Cote_Package;

public class FindOutlier {
	static int find(int[] integers) {
	    int oddnum = 0;
	    int odd = 0, even = 0;

	    for (int num: integers) {
	        if (num % 2 == 0)
	            even = num;
	        else {
	            oddnum++;
	            odd = num;
	        }
	    }
	    return oddnum > 1 ? even : odd;
	}
}
