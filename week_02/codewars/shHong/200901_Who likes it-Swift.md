# 02주차 Who likes it - Swift

## 풀이방법
```swift
func likes(_ names : [String]) -> String {
    var ans : String
    switch names.count {
    case 0:
        ans = "no one likes this"
    case 1:
        ans = "\(names[0]) likes this"
    case 2:
        ans = "\(names[0]) and \(names[1]) like this"
    case 3:
        ans = "\(names[0]), \(names[1]) and \(names[2]) like this"
    default:
        ans = "\(names[0]), \(names[1]) and \(names.count - 2) others like this"
    }
    return ans
}
```
* swift String formatting 방법과 switch문을 이용하여 작성했다.

## 다른사람의 풀이방법
 * codewars에 Swift가 없다.

## 배운점
* formatting, switch, function에서 array를 args로 받는 방법.

## 반성할점
* 많이 풀어보자.

## Action Item
* 최대한 스스로 풀어보고 다른사람들의 답지를 보자.
* xcode랑 친해지자.