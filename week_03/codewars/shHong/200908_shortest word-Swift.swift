func find_short(_ str: String) -> Int
{
    var min = Int.max
    let str_arr = str.components(separatedBy: " ")
    for str in str_arr{
        if str.count < min{
            min = str.count
        }
    }
    return min
}