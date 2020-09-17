# Take a ten minute walk

## 문제 설명
동서남북으로 가서 10번만에 제자리로 돌아오게 하기

## 나의 풀이
```java
public class TenMinWalk {
  public static boolean isValid(char[] walk) {
    
    int x = 0, y = 0;
    
    if(walk.length != 10) {
      return false;
    }
    
    for(char a : walk) {
      switch(a) {
        case 'e' : x++; break;
        case 'w' : x--; break;
        case 's' : y++; break;
        case 'n' : y--; break;  
      }
    }
    
    if(x == 0 && y == 0)
      return true;
    
    return false;
  }
}
```
* 변수를 만들어서 해결했다.

## 다른 사람 풀이
```java
import java.awt.Point;

public class TenMinWalk {
  public static boolean isValid(char[] walk) {
    Point point = new Point(0,0);
    for (char c : walk) {
            switch (c) {
                case 'n': point.translate(1,0); break;
                case 'e': point.translate(0,1); break;
                case 's': point.translate(-1,0); break;
                case 'w': point.translate(0,-1); break;
            }
        }
        return point.equals(new Point(0,0)) && walk.length == 10;
  }
}
```
* 포인트를 사용했다. 포인트 사용법을 알아두자. 
```java
public class TenMinWalk {
    public static boolean isValid(char[] walk) {
        String s = new String(walk);
        return s.chars().filter(p->p=='n').count()==s.chars().filter(p->p=='s').count()&&
                s.chars().filter(p->p=='e').count()==s.chars().filter(p->p=='w').count()&&s.chars().count()==10;
    }
}
```
* 스트림을 사용했다. 사용하지 않는게 가독성에 좋을 것 같다.

## 배운 점
- 요즘 기업 알고리즘 문제들을 그냥 봤는데 무서웠다. 갈길이 먼듯하다.

## 반성할 점
- 요즘 많이 게을러졌다... 열심히 공부하자
