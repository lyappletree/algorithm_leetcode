#include <iostream>

int main(int argc, char** argv)
{
   int a[9] = {1, -2, 3, 10, -4, 7, 2, -5, -2};
   int max = 0;
   int index = -1;
   int sum = 0;
   for (int i=0; i<9; i++)
    {
     sum = sum + a[i];
	 if (sum < a[i])
	   sum = a[i];
	 if (max < sum)
	  {
	    max = sum;
		index = i;
		std::cout<< "max....." << max <<"\n";
	  } 
    }
	
	std::cout<< "max....." << max <<"\n";
	std::cout<< "index...." << index<<"\n";
	std::cout<< "sum......" << sum << "\n";
	if (max > sum)
	  std::cout<<"max....."<< max <<"\n";
    return sum;
}