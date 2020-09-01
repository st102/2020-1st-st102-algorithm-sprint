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