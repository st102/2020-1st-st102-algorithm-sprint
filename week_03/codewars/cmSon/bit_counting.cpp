#define BINARY 2

unsigned int countBits(unsigned long long n){
  
  int bit_count = 0;
  
  while(n){
    bit_count += n % BINARY;
    n /= BINARY;
  }
  
  return bit_count;
}