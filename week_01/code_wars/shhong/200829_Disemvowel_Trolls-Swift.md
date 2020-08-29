# 01주차 Disemvowel Trolls - Swift

## 풀이방법
```swift
func disemvowel(_ s: String) -> String {
    let vowels : [Character] = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
    var str = s
    str.removeAll(where: {vowels.contains($0)})
    return str
}
```
* iOS개발을 위해 swift도 병행하기로 했다.
* swift의 기본문법만 숙지하고 작성했다. 
* python과 다르게 변수의 자료형에 굉장히 엄격하게 작동한다. ```let vowels : [Character] = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]```의 경우 ```let vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]```처럼 작성하면 removeAll 메서드가 작동하지 않는다.

## 다른사람의 풀이방법

### Best practice
```swift
func disemvowel(_ s: String) -> String {
  return s.replacingOccurrences(of: "[aeiou]", with: "", options: [.regularExpression, .caseInsensitive])
}
```
* 이해가 되질 않는다. 더 익숙해지고 많이 풀어봐야겠다.
* ```func replacingOccurrences(of target: String, with replacement: String, options: NSString.CompareOptions = [], range searchRange: NSRange) -> String``` target의 문자열을 replacement로 변경한다. 옵션은 생략이 가능하지만 이해가 가질 않는다. 
* ```import Foundation``` 해주어야 작동한다.

### Clever
```swift
func disemvowel(_ s: String) -> String {
  let vowels: [Character] = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
  
  return String(s.characters.filter { !vowels.contains($0) })
}
```
* 내 코드와 비슷하지만 불필요한 변수선언이 적다.
* ```filter { !vowels.contains($0) }``` 모음이 아닐 경우만 String으로 casting해서 return한다.
* best보다 길지만 이해가 쉽다.

## 배운점
* swift의 기본적인 문법, 특징.
* 자료형의 중요성.
* 갈길이 멀다는 것.

## 반성할점
* 언어는 다 비슷할거라는 오만함을 반성한다. 비슷한 점도 있지만 특징이 다 다르다.

## Action Item
* 최대한 스스로 풀어보고 다른사람들의 답지를 보자.
* xcode랑 친해지자.