#include <iostream>

doouble findMedian(int a[], int start1, int end1, int b[], int start2, int end2)
{
    int mid1 = (start1+end1)/2;
	int mid2 = (start2+end2)/2;
	
	if(start1 == end1)
	   return a[start1];
	if(start2 == end2)
	   return b[start2];
	if(a[mid1]< b[mid2])
	  {
	    mid1 = (mid1+size1)/2;
		mid2 = mid2/2;
		findMedian(a, mid1, size1, b, 0, mid2);
	  }
	else if(a[mid1] == b[mid2])
	   return a[mid1];
	else
	 {
	   mid2 = (mid2+ size2)/2;
	   mid1 = mid1/2;
	   findMedian(a, 0, mid1, mid2, size2);
	 }
}

int main()
{
  int a[4] = {1, 2, 3, 4};
  int b[4] = {5, 6, 7, 8};
  
  double x = findMedian(a, 0, 4, b, 0, 4);
  return 1;
}