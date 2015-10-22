#include <math.h> 
#include <iostream>
#include <stddef.h>
#include <map>
#include <string>

int getMinIndex(map<char, int> my_map)
{
  int min = 1000;
  std::map<char, int>::iterator it;
  for (it = my_map.begin(); it!= my_map.end(); it++)
  {
    if (min> it->second)
	  min = it->second;
  }
  return min;  
}

void printMap (map<char, int> my_map)
{
  std::map<char, int>::iterator it;
  for (it = my_map.begin(); it!= my_map.end(); it++)
     std::cout<<"map..."<< it->first <<" " << it->second <<"\n";
  std::cout<<"\n";
}

int getWindowSize(string str1, string str2)
{
   std::map<char, int> myStr2;
   for (int i=0; i< str2.length(); i++)
       myStr2.insert(std::pair<char, int>(str2[i], -1));
   printMap(myStr2);
	   
   int minWin = 100;   
   std::map<char, int>::const_iterator it;
   for (int i=0; i< str1.length(); i++)
    {
	   it = myStr2.find(str1[i]);
       if (it!= myStr2.end())
	    {
		  myStr2.erase(str1[i]);
	      myStr2.insert(std::pair<char, int>(str1[i], i));
		  int tmpMin = getMinIndex(myStr2);
		  if (minWin > (i-tmpMin+1) && tmpMin!=-1)
		  {
		     minWin = i-tmpMin+1;
			 std::cout<<"minWin...." << minWin <<"\n";
		  }
		  printMap(myStr2);
		}
	      
	}
	return minWin; 
}

int main()
{
  string str1 = "ADOBECODEBANC";
  string str2 = "ABC";
  int windows = getWindowSize(str1,str2);
  std::cout<< windows;
  return 1;
}