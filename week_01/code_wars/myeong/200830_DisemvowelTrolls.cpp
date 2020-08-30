# include <string>

std::string disemvowel(std::string str)
{
    int i=0;
  
    while(str[i]!='\0') {
      if( str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
         str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' ) {
        str.erase(i,1);
        i--;
      }
      i++;
    }
    return str;
}