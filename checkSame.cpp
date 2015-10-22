#include <iostream>
#include <stddef.h>
#include <vector>

std::vector<int> checkSame (int a[], int lengtha, int b[], int lengthb)
{
  int i = 0;
  int j = 0;
  std::vector<int> same;
  while (i!=lengtha && j!=lengthb)
  {
    if (a[i] == b[j])
	 {
	   same.push_back(a[i]);
	   i++;
	   j++;
	 }
	else if (a[i] < b[j])
	   i++;
    else
	   j++;	
  }
  return same;
}

int main()
{
  int a[5] = {1, 4, 7, 10, 13};
  int b[5] = {1, 3, 5, 7, 9};
  
  std::vector<int> m = checkSame (a, 5, b, 5);
  
  std::vector<int>::iterator it;
  
  for(it= m.begin(); it!=m.end(); it++)
    std::cout<<*it <<" ";
}