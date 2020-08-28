using namespace std;
std::string even_or_odd(int number) {
  string integer_function;
  if (number < 0) {
    number = -number;
  }

  if (number % 2 == 1) {
    integer_function = "Odd";
  } else if (number % 2 == 0) {
    integer_function = "Even";
  }
  return integer_function;
}