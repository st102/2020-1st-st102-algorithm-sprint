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

