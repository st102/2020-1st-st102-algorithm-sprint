package week_02.codewars.cmSon;

public class SquareDigit {

    public int squareDigits(int n) {
      String square_of_digits="";
       while(n != 0){
            square_of_digits = Integer.toString((int)Math.pow(n%10, 2)) + square_of_digits;
            n /= 10;
          }
      return  Integer.parseInt(square_of_digits);
    }
  
  }