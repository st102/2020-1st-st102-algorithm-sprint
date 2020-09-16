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