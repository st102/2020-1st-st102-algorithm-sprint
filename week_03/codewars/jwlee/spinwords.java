public class SpinWords {

  public String spinWords(String sentence) {
    
    StringBuilder result = new StringBuilder();

    for(String index : sentence.split(" ")) {
      
      if(index.length() > 4) {
        StringBuilder rev = new StringBuilder(index);
        rev.reverse();
        result.append(rev);
      }
      else
        result.append(index);
      result.append(" ");
    }
    
    return result.toString().substring(0, sentence.length());
  }
}


