#include <iostream>
#include <stddef.h>
#include <string>
#include <vector>

int numberToString(int number)
{
   
   char *intStr = itoa(number);
   string str = string(intStr);
   std::vector<int> number2;
   int m =0;
   while(str[m]!='0')
   {
     number2.push_back(std::stoi(str[m]));
     m = m+1;
   }
   
   int len = number2.size();
   int counts[len];
   
   for (int i=len-1; i>=0; i--)
    {
	  int count =0;
	  if(number2[i]>=1 && number2[i]<10)
	    {
		   if (i= len-1)
		      count = count +1;
		   else
		      count = count + counts[i+1]; 
		}
		
	  if(i<len-1)
	   {
	     if (number[i]!=0)
		  {
		     int con = number[i]*10+ number[i+1];
			 if (con>=10 && con<=26)
			   {
			      if(i<length-2)
				    count+= counts[i+2];
				  else
				    count+=1;
			   }
		  }
	   }
	  counts[i] = count;
	}
   
   
}

int main()
{
  int number = 12258;
  
  std::count<< numberToString(12258);
}