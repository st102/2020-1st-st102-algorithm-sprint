# 02주차 Count bits - swift

## 문제 설명
* 입력받은 정수를 2진수로 변환 후 1의 개수 반환.

## 풀이방법
```swift
import XCTest


func countBits(_ n : Int) -> Int{
    let bits = String(n, radix: 2)
    var count = 0
    for bit in bits{
        if bit == "1"{
            count += 1
        }
    }
    return count
}


class SolutionTest: XCTestCase {
    override func setUp() {
        super.setUp()
    }
    override func tearDown() {
        super.tearDown()
    }
    
    func test_countBits() {
        XCTAssertEqual(countBits(1), 1)
        XCTAssertEqual(countBits(3), 2)
        XCTAssertEqual(countBits(1234), 5)
    }
}


SolutionTest.defaultTestSuite.run()
```
* 비트변환 후 1일 경우 cnt를 증가시킨다.
* 처음으로 swift 테스트코드를 포함시켰다. 파이썬과 다르게 setUp과 TearDown메서드를 override해야한다.

## 다른사람의 풀이방법

### Best practice
```swift
func countBits(_ n: Int) -> Int {
    return n.nonzeroBitCount
}
```
* 저런 메서드가 있는 줄 몰랐다. 하나 배워간다.

### Clever
```swift
func countBits(_ n: Int) -> Int {
  return String(n, radix: 2).filter { $0 == "1" }.count
}
```
* 이 코드는 파이썬 스럽고 내가 알 수 있는 범위인 것 같다.
* filter와 count메서드는 이전에도 써봤고 2진변환도 이번에 알았기 때문에 다음에 더 잘 할 수 있을 것 같다.

## 배운점
* 2진수로 변환하는 법. Apple의 swift documents는 정리가 너무 잘 되어 있어서 보기 좋다. 자주 보자!
* swift의 testcode 작성법.

## 반성할점
* 화이팅!

## Action Item
* 테스트코드 작성.