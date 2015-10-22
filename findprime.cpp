#include <iostream>

int countPrimes(int n) {
       int a[n];
       for(int i=1; i<n; i++)
          a[i] = 0;
       int i=1;
       int p=0;
	   int pp=0;
       for(; i<n; i++) 
       {
          if(a[i] ==0)
          {
               pp=i+1;
			   std::cout<<"p...."<<pp<<"\n";
               while(p<=n)
               {
                   p+=pp;
                   if (p-1<n)
                     a[p-1] = 1;
                   // std::cout<<"ying liu.....2...\n";
               }
               // i = 1;
               // std::cout<<"ying liu.....1...\n";
          } 
       }
       int count = 0;
       for(int j=1; j<n; j++)
         if(a[j]==0)
		 {
           count++;
		   // std::cout<<(j+1)<<"\n"; 
		  }
       return count;
    }

int main()
{
  int count = countPrimes(1500000);
  std::cout<< count;
}