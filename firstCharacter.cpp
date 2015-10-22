#include <iostream>
#include <stddef.h>
#include <string>
#include <map>

std::string rotateAString (std::string str, int n)
{
   int i =0;
   std::string str1 = "";
   std::string str2 = "";
   bool flag = false;
   std::cout<<"Ying Liu.. str..." << str <<"\n";
   while (str[i]!='\0')
   {
     if (flag == false)
        str1+= str[i];
     else
	    str2+= str[i];
     if (i == n-1)
	    flag = true;
     i++;
   }
   
   return (str2+str1);
}

int main()
{
  std::string str = "abaccdeff";
  std::map<char, int> visited;
  std::map<char, int>::iterator it;
  
  int i = 0;
  while(str[i]!='\0')
   {
      it = visited.find(str[i]);
      if ( it!= visited.end())
	     it->second++;
	  else
	    visited.insert(std::pair<char, int>(str[i], 1)); 
	  i++;	    
   }
   
  for (it = visited.begin(); it!= visited.end(); it++)
     if(it->second == 1)
	    break;
  
  std::cout<< it->first <<"\n"; 

  std::string str_rotate = rotateAString (str, 2);  
  std::cout<< str_rotate <<"\n";
}