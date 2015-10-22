#include <iostream>
#include <stddef.h>
#include <string>

bool isPalindrome (std::string str)
{
  int len = str.length();
  if (str =="")
     return false;
  int j = len-1;
  int i = 0;
  while(i!=j)
   { 
      if(str[i]!=str[j])
	    return false;   
      i++;
	  j--;
   }
   return true;
}

int split(std::string str)
{
   int len = str.length();
   int minNum[len][len];
   
	for (int i=0; i<len; i++)
	  for (int j=0; j<len; j++)
	     minNum[i][j] = 0;
   
   for ( int i=0; i<len; i++)
    {
	  for (int j=0; j<len; j++)
	   {
	     std::string str2 = str.substr(i, j);
	     if (isPalindrome (str2))
		    minNum[i][j] = 0;
		 else
		   {
		      // std::cout<<"ying LIU....2\n";
		      int min = 10000;
		      for (int k=i; k<j; k++)
			   {			     
			     int tmp = minNum[i][k] + minNum[k+1][j]+1;
			     if ( min > tmp )
				    min = tmp;
			   }
			   minNum[i][j] = min;
		   }
	   }
	}
	
	std::cout<< minNum[0][len-1];
	
	for (int i=0; i<len; i++)
	 {
	  for (int j=0; j<len; j++)
	    {
		  std::cout<<minNum[i][j]<<" ";
		}
	  std::cout<<"\n";
	 }
   return minNum[0][len-1];
}

int split2(std::string str)
{
   int len = str.length();
   int minNum[len];
   for (int i=0; i<len; i++)
    {
	   std::string str2 = str.substr(0, i);
	   if (isPalindrome (str2))
	     minNum[i] = 0;
	   else
	     {
		   int min = 10000;
		   for(int j=0; j<i; j++)
		     {
			    if (isPalindrome(str.substr(j+1,i)))
				 {
			        int tmp = minNum[j] + 1;
					if (min> tmp)
					  min = tmp;
				 }
			 }
		   minNum[i] = min;
		 }
	}
	
	return minNum[len-1];
}


int main()
{
   std::string str = "abbab";
  // std::cout<< split2(str) <<"\n";
  std::cout<< split(str) <<"\n";
}