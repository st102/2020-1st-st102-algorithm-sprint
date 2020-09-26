#include <vector>
#include <cmath>
using namespace std;
class Same {
public :
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
      int count=b.size();
      int semi_count=0;
      int cut=0;
      for(int i=0; i<b.size(); i++) {
        semi_count=0;
        for(int j=0; j<a.size(); j++) {
          if(b[i]==pow(a[j],2)) { 
            semi_count++; 
            cut=j;
          }
        }
        if(semi_count>0) {
          b.erase(b.begin()+i);
          a.erase(a.begin()+cut);
          i--;
          count--;
        }
      }
      if(count==0 || a.size()+b.size()==0) {
        return true;
      } else return false;
    }
};