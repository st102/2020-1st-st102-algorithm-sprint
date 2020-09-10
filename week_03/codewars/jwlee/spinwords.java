public class SpinWords {

  public String spinWords(String sentence) {
    
    StringBuilder sb = new StringBuilder();

    for(String a : sentence.split(" ")) {
      
      if(a.length() > 4) {
        StringBuilder sb2 = new StringBuilder(a);
        sb2.reverse();
        sb.append(sb2);
      }
      else
        sb.append(a);
      sb.append(" ");
    }
    
    return sb.toString().substring(0, sentence.length());
  }
}


