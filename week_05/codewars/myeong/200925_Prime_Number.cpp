bool isPrime(int num) {
  
  if(num<=0 || num == 1){
    return false;
  }
  for(int i = 2; i<=sqrt(num) ; i++){
    if(num % i == 0)
      return false;
    
  }
  return true;
}