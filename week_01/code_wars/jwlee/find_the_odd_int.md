# Find the odd int

## 문제 설명
홀수번 존재하는 배열의 값을 찾아서 리턴하기
Given an array of integers, find the one that appears an odd number of times.

## 나의 풀이 방법

### 문제 풀이 코드

public class FindOdd {
    public static int findIt(int[] a) {

        for (int i = 0; i < a.length; i++) {
            int count = 0;
            for (int j = 0; j < a.length; j++) {
                if (a[i] == a[j])
                    count++;
            }
            if (count % 2 == 1)
                return a[i];
        }
        return 0;
    }
}

중첩 for문을 이용해서 배열의 모든 값에 접근하면서 같으면 count를증가시키고, count 가 홀수인 경우에 출력, 아닌 경우는 다시 for 문으로 돌아가서 다시 찾는다.

accessed all elements in array running by two nested for loops. if there is the same element in array, increase variable named count. If count is odd, return. or keep acessing the other elements back in loops.


## 다른 사람의 풀이 방법

### Best Practice

public class FindOdd {
  public static int findIt(int[] A) {
    int odd=0;
    for (int item: A)
      {
        odd = odd ^ item;
      }

    return odd;
  }
}

XOR 을 이용해서 짝수개이면 면 0, 홀수개이면1이 나오도록 했다. 매우 똑똑하시다.
XOR will cancel out everytime you XOR with the same number. so every pair should cancel out leaving the odd number out. must be super smart.
 


## 배운 점
- 배열의 모든 값에 접근하지 않고도 풀 수 있게 고민하자.
Think about the way without an unnecessary array access.

- XOR 연산자에 대해서 배웠다. 유용할 것 같다.
Learned about XOR operator. will be useful.

- 이번에 저번에 피드백 받은 코드 포맷팅에 신경을 썼는데 훨씬 깔끔해보인다.
Code formatting I got some feedback for, I think that makes it look much cleaner and better.

## 반성할 점
- 처음에 문제를 잘못 이해해서 한참 헤맸다. 문제를 꼼꼼히 읽자.
misunderstood the instruction and kept me stuck in the beginning. Read the instruction thoroughly.


- Best 코드와 내 코드를 비교해 보니 가독성이 많이 떨어지고 긴 경우에는 이해하기 힘들것 같다. 앞으로 메소드나 연산자를  적극 활용하자! 
Comparing my code with the best code, I thought it might be hard to read and understand in case it is long. 

## Action Item
- 자바 메소드 공부해서 실습해보기
Practice methods of Java

- 코드 포맷팅에 항상 신경쓰면서 습관되도록 하기
Make it a habit to care about formatting the code.
