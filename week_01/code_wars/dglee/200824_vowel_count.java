package Cote_Week01;

public class Vowel {

	public static int get_count(String str)
	{
		int count=0;
		char[] chr = str.toCharArray();

		for(char e : chr)
		{
			switch(e)
			{
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' :
				count++;
			}
		}
		return count;
	}

}
