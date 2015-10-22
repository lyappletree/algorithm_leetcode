#include<iostream>

int findTurningNumber(int number[], int length)
{
  int i=0;
  int j= length-1;
  while(i!=j)
  {
    int mid;
    if((i+j)%2 == 0)
       mid = (i+j)/2;
	if((i+j)%2 == 1)
	   mid = (i+j-1)/2;
	if(number[mid-1]< number[mid] && number[mid]<number[mid+1])
	     i = mid; 
    else if(number[mid-1]>number[mid] && number[mid]>number[mid+1])
	     j = mid;
    else if(number[mid-1]< number[mid] && number[mid]>number[mid+1])
	    return number[mid];
	else if(number[mid-1]> number[mid] && number[mid]<number[mid+1])
	    return number[mid];
  }
  return number[i];
}

int main()
{
  int number[10] = {1,2,3,4,5,10,9,8,7,6};
  
  std::cout<<findTurningNumber(number, 10);
  
  return 1;
}