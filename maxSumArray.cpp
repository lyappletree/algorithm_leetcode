#include <math.h> 
#include <iostream>
#include <stddef.h>

int maxSum(int a[], int length)
{
   int b[length];
   b[0] = a[0];
   if (a[0]> a[1])
     b[1] = a[0];
   else
     b[1] = a[1];
	 
   for (int i=2; i< length; i++)
     {
	    int tmp1 = a[i]+ b[i-2];
		if (tmp1 > b[i-1])
		  b[i] = tmp1;
		else
		  b[i] = b[i-1];
	 }
   return b[length-1]; 
}

int main()
{
  int a[9] = {4, 2, 1, 6, 5, 7, 3, 9};
  
  int sum_value = maxSum(a, 9);
  std::cout<< sum_value; 
}