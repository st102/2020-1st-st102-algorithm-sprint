package Cote_Package;

public class Bit_Count {
	public static int countBits(int n){
		String onebit = Integer.toBinaryString(n).replaceAll("0","");
		  return onebit.length();
	}
}
