# 02주차 Create Phone Number - Python

## 풀이방법
```swift
func create_phone_number(_ number : [Int]) -> String{
    let num = number.map{String($0)}
    return "(\(num[0...2].joined())) \(num[3...5].joined())-\(num[6...9].joined())"
}
```
* map()을 이용하여 integer형 Array를 string으로 바꿔 joined 메서드 사용가능하게 했다.

## 배운점
* 파이썬과 다르게 엄격한 자료형규칙이 있다.
* 같은 array형이어도 element가 int 인가 string인가에 따라 사용가능한 메서드가 다르다.

## 반성할점
* 기본문법 숙지

## Action Item
* 최대한 혼자서 풀어보기!