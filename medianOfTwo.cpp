#include <iostream>

int max(int x1, int x2)
{
  return x1>x2? x1:x2;
}

int min(int x1, int x2)
{
  return x1<x2? x1:x2;
}


double findMedian(int a[], int start1, int end1, int b[], int start2, int end2)
{
    int N = end1-start1+1;
	int M = end2-start2+1;
	std::cout<<"N...."<<N<<"\n";
	std::cout<<"M...."<<M<<"\n";
	
	if( N==1 && M==1)
	  return (a[0]+a[1])/2.0;
	if( N==1 && M%2==1)
	 {  std::cout<<"Ying LIU..2..\n";
	    int m = M/2;
		if (a[0]<b[m]&& a[0]>b[m-1])
		{ std::cout<<"Ying LIU....\n";
		  return (a[0]+b[m])/2.0;
		 }
		if (a[0]<b[m-1])
		  return (b[m-1]+b[m])/2.0;
		if (a[0]>b[m]&& a[0]<b[m+1])
		  return (a[0]+b[m])/2.0;
		if(a[0]> b[m+1])
		  return (b[m+1]+b[m])/2.0;
		
	 }
	 
	 if( N== 1 && M%2==0)
	 {
	    int m = M/2;
		if(a[0]<b[m] && a[0]>b[m-1])
		   return a[0];
		if(a[0]<b[m-1])
		   return b[m-1];
	 }
	 
	 if( N==2 && M==2 )
	   return (max(a[0],b[0])+ min(a[1], b[1]))/2.0;
	   
	 if( N==2 && M%2 == 1)
	 {
	   int m = M/2;
	   if(a[0]<b[m]&& a[1]>b[m])
	     return b[m];
	   if(a[1]<b[M] && a[1]>b[M-1])
	     return a[1];
	   if(a[1]<b[M-1])
	     return b[M-1];
	   if(a[0]>b[m] && a[0]<b[m+1])
	     return a[0];
	   if(a[0]>b[m+1])
	     return b[m+1];
	 }
	 
	 if( N==2 && M%2 == 0)
	 {
	   int m = M/2;
	   if(a[1]<b[m] && a[0]>b[m-1])
	     return (a[0]+a[1])/2.0;
	   if(a[1]<b[m-2])
	     return (b[m-1]+b[m-2])/2.0;
	   if(a[1]<b[m-1] &&  a[1]> b[m-2])
	     return (a[1]+ b[m-1])/2.0;
	   if(a[1]>b[m-1] && a[0]<b[m-1])
	     return (a[1]+ b[m-1])/2.0;
	   if(a[0]>b[m] && a[0]<b[m+1])
	     return (a[0]+b[m])/2.0;
	   if(a[0]>b[m])
	     return (b[m]+b[m+1])/2.0;		 
	 }
	 
	 int mid1 = N/2;
	 int mid2 = M/2;
	 if(a[mid1]< b[mid2])
	   findMedian(a, mid1, end1, b, start2, mid2);
	 else if(a[mid1]==b[mid2])
	   return a[mid1];
	 else
	   findMedian(a, start1, mid1, b, mid2, end2);
}

int main()
{
  int a[4] = {2,5};
  int b[4] = {3, 4};
  
  double x = findMedian(a, 0, 1, b, 0, 1);
  std::cout<<x;
  return 1;
}