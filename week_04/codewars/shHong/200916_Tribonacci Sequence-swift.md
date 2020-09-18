# 04주차 Tribonacci Sequence - swift

## 문제 설명
* 트리보나치 구현

## 풀이방법
```swift
func tribonacci(_ signature: [Int], _ n: Int) -> [Int] {
  var tribonacciArray : [Int] = []
  for idx in 0..<n{
    if idx == 0 || idx == 1 || idx == 2{
      tribonacciArray.append(signature[idx])
    }
    else{
      tribonacciArray.append(tribonacciArray[idx-1] + tribonacciArray[idx-2] + tribonacciArray[idx-3])
    }
  }
  return tribonacciArray
}
```
* python과 같은 방법으로 풀이

## 다른사람의 풀이방법

### Best practice
```swift
func tribonacci(_ signature: [Int], _ n: Int) -> [Int] {
  guard n > 0 else { return [] }
  guard n > 3 else { return [] + signature.prefix(n) }
  var result = signature
  for ind in 3..<n {
    result.append(result.suffix(3).reduce(0, +))
  }
  return result
}
```
* guard문을 이용하여 코드의 안정성을 높였다. 
* prefix와 suffix를 이용해 python의 슬라이싱처럼 사용했다.

### Clever
```swift
func tribonacci(_ signature: [Int], _ n: Int) -> [Int] {
    guard n > 3 else {
        return Array(signature.prefix(n))
    }
    
    var result = signature
    var next = result.reduce(0, + )
    for index in 0..<(n - 3) {
        result.append(next)
        next = next * 2 - result[index]
    }
    return result
}
```
* best와 비슷하다.

## 배운점
* guard, prefix, suffix

## 반성할점
* .

## Action Item
* 많은 예제 풀기.