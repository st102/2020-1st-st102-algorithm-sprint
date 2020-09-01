std::string get_middle(std::string input) 
{
  int mid;
  mid=input.length()/2;
  
  if ( input.length()==1 ) {
    return input;
  }
  else if ( input.length()%2==1 && input.length()!=1 ) {
    return input.substr(mid,1);
  }
  else if ( input.length()%2==0 ) {
    return input.substr(mid-1,2);
  }
}