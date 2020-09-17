unsigned int countBits(unsigned long long n){
  unsigned long long mok=-1;
  unsigned long long remind;
  int recount=0;
  while(mok!=0) {
    mok=n/2;
    remind=n-mok*2;
    if (remind==1) { recount++; }
    n=mok;
  }
  return recount;
}