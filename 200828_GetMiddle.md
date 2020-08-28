# Vowel Count

## 문제 설명

*   문자열에서 중간 글자 찾기

## 나의 풀이 방법

```cpp
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
```

*   if문을 활용하여 3가지의 경우로 나눠서 문자가 1개일때, 홀수개일때, 짝수개일때로 구분하였다.
*   구분후에 mid라는 변수로 문자열 길이의 중간을 찾아 substr을 활용하여 출력했다.

## 다른 사람의 풀이 방법

### Best Practice

```cpp
std::string get_middle(std::string input) 
{
  int i = input.length();

  if ((i % 2) == 0) 
    return input.substr(i/2 - 1, 2);
    
  else
    return input.substr(i/2, 1);
}
```

*   나와 비슷한 방법으로 풀었지만 나보다 더 간단하다. input.lnegth를 변수에 넣어 간단하게 풀이하였다.

###Clever

```cpp
std::string get_middle(std::string input) 
{
  return input.substr((input.size()-1)/2,(input.size()+1)%2+1);
}

*   substr에서 몫 부분으로 중간을 찾고 몇 개를 할지를 나머지로 하여 return 하였다.

## 배운 점

*   평소에 배열을 자주 사용하고 string에 미숙한 부분이 있었는데 이번 문제를 풀며 찾아보며 보완하게되었다.

## 반성할 점

*   찾아볼때 제대로 찾아보아야할 것 같다. 자바에서는 substring인데 잘못찾아 
    그걸로 계속 코드를 작성하다 나중에 발견했다.

## Action Item

*   string을 정복하는 그날을 위하여!!