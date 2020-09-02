func create_phone_number(_ number : [Int]) -> String{
    let num = number.map{String($0)}
    return "(\(num[0...2].joined())) \(num[3...5].joined())-\(num[6...9].joined())"
}