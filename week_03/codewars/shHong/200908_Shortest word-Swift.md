# 02주차 Shortest word - Swift

## 문제 설명
* 입력받은 배열에서 정수형 원소만 추출한다.

## 풀이방법
```swift
func find_short(_ str: String) -> Int
{
    var min = Int.max
    let str_arr = str.components(separatedBy: " ")
    for str in str_arr{
        if str.count < min{
            min = str.count
        }
    }
    return min
}
```
* 이번엔 스위프트 문제도 있어서 같이 풀었다.
* 메서드를 사용하기 보단 아는 범위에서 C스럽게 작성했다.

## 다른사람의 풀이방법

### Best practice
```swift
func find_short(_ str: String) -> Int
{
  return str.components(separatedBy: " ").map { $0.count }.min() ?? 0
}
```
* map()을 통해 원소의 길이를 계산 후 mapping하고 그 중 최소값을 구했다.
* 잘 짜여졌고 가독성도 좋다. 이렇게 짤 수 있을 때 까지 연습해야겠다.

## 배운점
* components, map과 같은 내장함수 사용법

## 반성할점
* 다음번엔 테스트코드까지 포함시켜보자.

## Action Item
* 최대한 아는대로 짜고 best code를 보며 배워가자!