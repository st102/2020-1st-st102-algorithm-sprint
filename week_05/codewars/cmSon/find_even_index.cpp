#include <vector>
using namespace std;

int find_even_index (const vector <int> numbers) {
  int total_sum = 0;
  int right_sum = 0;
  int left_sum = 0;
  
  for(auto num : numbers) total_sum += num;

  for(int i = 0; i < numbers.size(); i++){
    
    right_sum = total_sum - left_sum - numbers[i];
    
    if(left_sum == right_sum) return i;
    else left_sum += numbers[i];
  }
  
  return -1;
}