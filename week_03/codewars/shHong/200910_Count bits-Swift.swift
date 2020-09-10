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