# 02주차 Sum of Digits / Digital Root  - Swift

## 풀이방법
```swift
func digitalRoot(of number: Int) -> Int {
    var num = String(number).digits
    var new_num : Int = 0
    while num.count != 1{
        new_num = num.reduce(0, +)
        num = String(new_num).digits
    }
    return new_num
}
extension StringProtocol  {
    var digits: [Int] { compactMap(\.wholeNumberValue) }
}
```
* StringProtocol을 이용해 문자열을 정수의 list로 변환 후 더하는 과정을 거쳤다.
* 이 방법을 찾아서 시도했을 때 xcode에서는 동작하지만 codewars에서는 동작하지 않았다.

## 다른사람의 풀이방법

### Best practice
```swift
func digitalRoot(of number: Int) -> Int {
    return (1 + (number - 1) % 9)
}
```
* 파이썬과 같은 방법

### Clever
```swift
func digitalRoot(of number: Int) -> Int {
  let total = String(number).characters.map({ Int(String($0))! }).reduce(0, +)
  return total % 10 == total ? total : digitalRoot(of: total)
}
```
* swift의 map()활용을 잘 보여준 것 같아 clever로 선택했다.
* 재귀적으로 잘 표현하고 내장함수를 잘 사용했다.

## 배운점
* map()활용법

## 반성할점
* 아직 너무 어렵다.

## Action Item
* 최대한 스스로 풀어보고 다른사람들의 답지를 보자.
* xcode랑 친해지자.