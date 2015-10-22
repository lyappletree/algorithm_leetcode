#include <iostream>

int main(int argc, char** argv)
{
   int a[8] = {1, -2, 3, 10, -4, 7, 2, -5};
   int f[8] = {0, 0, 0, 0, 0, 0, 0, 0};
   int max = -100;
   for (int i=0; i<8; i++)
    {
      if (i==0 || f[i-1]<=0)
	     f[i] = a[i];
	  else
	     f[i] = f[i-1]+a[i];
	  if (max<f[i])
	    max = f[i];
	}
   // print f
   std::cout<<"max...."<< max <<"\n";
   for (int i=0; i<8; i++)
     std::cout<<f[i]<<" ";
   return max; 
}