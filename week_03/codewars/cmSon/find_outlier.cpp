#include <vector>

using namespace std;

int FindOutlier(vector<int> arr)
{
    int even_result;
    int odd_result;

    int even_count = 0;
  
    for(auto number: arr){
      if(number % 2 == 0) {
        even_result = number;
        even_count++;
      }else{
        odd_result = number;
      }
    }
  
    return (even_count > 1)? odd_result : even_result;
}