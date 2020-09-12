import java.util.Arrays;

public class FindOutlier{
  static int find(int[] integers){
    
  int[] odd = Arrays.stream(integers)
                .filter(i -> (i % 2 == 0))
                .toArray();
  int[] even = Arrays.stream(integers)
                 .filter(i -> (i % 2 != 0))
                 .toArray();
    
    
  return odd.length > 1 ? even[0] : odd[0];

}

}

