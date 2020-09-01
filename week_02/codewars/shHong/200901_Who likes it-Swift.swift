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