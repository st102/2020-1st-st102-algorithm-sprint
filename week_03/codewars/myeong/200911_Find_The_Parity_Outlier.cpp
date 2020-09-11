int FindOutlier(std::vector<int> arr)
{
  std::vector<int>::iterator itor=arr.begin();
  std::vector<int> odd;
  std::vector<int> even;
  for(; itor != arr.end(); itor++) {
    if(*itor % 2 == 0) {
      even.push_back(*itor);
    } else odd.push_back(*itor);
  }
  if(even.size()==1) {
    return even[0];
  }
  else return odd[0];
}