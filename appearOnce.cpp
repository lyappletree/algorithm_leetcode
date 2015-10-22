#include <iostream>
#include <map>

char FindFirstAppear(char* head)
{
  map<char, int> mymap;
  map<char, int>::iterator it;
  char* p = head;
  std::cout<<"ying liu...2\n";
  while(*p!='\0') 
  {
    it = mymap.find(*p);
	  std::cout<<"ying liu..."<<*p<<"\n";
    if(it== mymap.end())
       mymap.insert(std::pair<char,int>(*p,1));
	else
	   it->second++;
    p++;
  }
  for (it = mymap.begin(); it!= mymap.end(); it++)
    if(it->second== 1)
	  break;
  return it->first;
}

int main()
{
  char* str = "abbaccdeff";
  char a = FindFirstAppear(str);
  std::cout<<a ;
  return 1; 
}