int solution(int number) 
{
  int multiple_sum=0;
  
  for(int i=1; i<number; i++)
  {
    if( i%3==0 || i%5==0) 
    {
      multiple_sum += i;
    }
  }
  
  return multiple_sum;
}