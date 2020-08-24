ECHO가 설정되어 있습니다.
#include <stddef.h>

size_t get_count(const char *s)
{
  int vow=0; //모음의 개수를 저장할 변수
  int len=0; //입력받은 문자열의 길이를 저장할 변수
  
  //문자열의 길이 구하기
  while(s[len]!=0){
    len++;
  }
  
  //모음의 개수를 구하기 (switch-case 사용)
  for (int i=0;i<len;i++){
    switch(s[i]){
        case 'a' : vow+=1;  break;
        case 'e' : vow+=1;  break;
        case 'i' : vow+=1;  break;
        case 'o' : vow+=1;  break;
        case 'u' : vow+=1;  break;
        default: break;
    }
  }
  
  return vow;
}