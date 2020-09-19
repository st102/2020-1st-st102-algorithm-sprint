std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result = signature;

    for (int i = 3; i < n; i++){
      int next_number = result[i - 3] + result[i - 2] + result[i - 1];
      result.push_back(next_number);
    }
    if (n < 3) result.resize(n);
    return result;
}