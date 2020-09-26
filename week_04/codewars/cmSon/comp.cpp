#include <vector>
#include <algorithm>

using namespace std;
class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
      for(int i = 0; i < a.size(); i++)
        a[i] *= a[i];
  
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      
      return a == b;
    }
};