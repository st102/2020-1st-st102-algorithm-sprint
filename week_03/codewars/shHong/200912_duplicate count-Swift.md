# 03주차 duplicate count - Swift

## 문제 설명
* 입력받은 문자열에서 중복된 단어의 개수를 반환한다.

## 풀이방법
```swift
import XCTest


func countDuplicates(_ s:String) -> Int {
    var ret = 0
    let mapitem = Array(s.lowercased()).map { ($0, 1) }
    let counts = Dictionary(mapitem, uniquingKeysWith: +)
    for c in counts{
        if c.value > 1{
            ret += 1
        }
    }
    return ret
}


class SolutionTest: XCTestCase {
    override func setUp() {
        super.setUp()
    }
    override func tearDown() {
        super.tearDown()
    }
    
    func test_countBits() {
        XCTAssertEqual(countDuplicates("abcdefg"), 0)
        XCTAssertEqual(countDuplicates("aabbccdd"), 4)
        XCTAssertEqual(countDuplicates("aabBCCcdde"),4)
    }
}

SolutionTest.defaultTestSuite.run()
```
* dictionary를 이용해 문제를 풀었다.

## 다른사람의 풀이방법

### Best practice
```swift
func countDuplicates(_ s:String) -> Int {
    var counts: [String: Int] = [:]
    for character in Array(s) {
        counts[character.lowercased(), default: 0] += 1
    }
    return counts.values.filter{ $0 > 1 }.count
}
```
* filter를 사용해 불필요한 반복을 줄였다. 내 코드보다 쉽고 간결하다.

### Clever
```swift
func countDuplicates(_ s:String) -> Int {
  return s.lowercased().reduce(into: [:]) { $0[$1, default: 0] += 1 }.filter { $0.1 > 1 }.count
}
```
* 너무 간결해보인다. 난 왜 이렇게 못짤까

## 배운점
* dictionary 사용법. 

## 반성할점
* 더 열심히 공부해야겠다.

## Action Item
* 최대한 아는대로 짜고 best code를 보며 배워가자!