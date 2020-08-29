package Cote_Package;

public class Middle_Character {
	public static String getMiddle(String word){
		int length = word.length();
		int half = length/2;
		
		if(length%2==0)
			return word.substring(half-1,half+1);
		
		return word.substring(half,half+1);
	}

}
