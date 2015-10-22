#include <iostream>

int main(int argc, char** argv)
{
   int a[4] = {6, 1, 2, 7};
   int f[4] = {0, 0, 0, 0};
   f[0] = 6;
   // f[1] = 1;
   for (int i=1; i< 4; i++)
      if (i-2 <0)
	     f[i] = f[i-1];
      else if (a[i]+ f[i-2] >= f[i-1] && i-2>=0)
	      f[i] = a[i] + f[i-2];
	  else
	      f[i] = f[i-1];
   std::cout<< f[0] <<" " <<f[1] <<" "<< f[2]<< " "<< f[3]; 
}