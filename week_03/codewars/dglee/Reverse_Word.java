package Cote_Package;

public class Reverse_Word {
	public String spinWords(String sentence) {
	    StringBuffer strbuf = new StringBuffer();
	    String[] wordarr = sentence.split(" ");
	    String output="";
	    for(String word : wordarr){
	      if(word.length() > 4){
	        output += strbuf.append(word).reverse().toString() + " ";
	        strbuf.setLength(0);
	      }
	      
	      else
	        output += word + " ";
	    }
	    return output.substring(0,output.length()-1);
	  }
}
