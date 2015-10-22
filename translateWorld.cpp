#include <vector>
#include <iostream>

int translateWorld( int number[], int length)
{
  // table
  char table[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  int f[length];
  for(int i=0; i<length; i++)
   {
     if(i==0)
	 {
	    f[i]=1;
		std::cout<<"f[i]......"<< f[i] <<"...i..."<< i <<"\n";
	 }
	 else if(i==1)
	    f[i]=2;
	 else
	  {
	    f[i]=f[i-1]*1;
	    if ((number[i-1]*10+number[i])<= 26)
		 {
		  std::cout<<"f[i]......"<< f[i] <<"...i..."<< i <<"\n";	
		  std::cout<<"f[i-2]......"<< f[i-2]<<"\n";	
		  f[i] = f[i]+f[i-2]*1;  
		 }
        std::cout<<"f[i]...final..."<< f[i] <<"...i..."<< i <<"\n";		  
	  }
	  
   }
   
  return f[length-1];
}


int main()
{
  int number[5] = {1,2,2,5,8};
  std::cout<< translateWorld( number, 5);
  return 1;
}