using namespace std;

std::string likes(const std::vector<std::string> &names)
{
  string str=" likes this";
  string strs=" like this";
  string restr;
  int others=names.size()-2;
  
  if(names.size()==0) {
    restr="no one"+str;
  }
  else if(names.size()==1) {
    restr=names[0]+str;
  }  
  else if(names.size()==2) {
    restr=names[0]+" and "+names[1]+strs;
  }
  else if(names.size()==3) {
    restr=names[0]+", "+names[1]+" and "+names[2]+strs;
  }
  else if(names.size()>=4) {
    restr=names[0]+", "+names[1]+" and "+to_string(others)+" others"+strs;
  }
    return restr;
}