func disemvowel(_ s: String) -> String {
    let vowels : [Character] = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
    var str = s
    str.removeAll(where: {vowels.contains($0)})
    return str
}