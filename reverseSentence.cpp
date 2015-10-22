#include<iostream>

void Reverse(char* begin, char* end)
{
std::cout<<"Ying Liu. 4...\n";
  while(begin < end)
  {  std::cout<<"Ying Liu. 5...\n";
    char tmp;
	char tmp2;
	std::cout<<"Ying Liu. 7...\n";
	tmp = *begin;
	std::cout<<"Ying Liu. 8..."<< *end<<"  "<<*begin<<"\n";
	tmp2 = *end;
	std::cout<<"tmp2....."<< tmp2 <<"\n";
	*begin = tmp2;
	std::cout<<"*being...."<<*begin<<"\n";
	std::cout<<"Ying Liu. 9...\n";
	*end = tmp;
	std::cout<<"Ying Liu. 6...\n";
	begin++;
	end--;
	
	std::cout<<"Ying Liu. 3...\n";
  }
}

int main()
{
  char* str = "I am a student.";
  char* begin = str;
  char* end = str;
  while(*end!='\0')
    end++;
  end--;
  *begin = 'a';
  std::cout<<"Ying Liu..2.."<<*end<<"\n";
  
  //reverse whole sentence
  Reverse(begin, end);
  char* pEnd;
  char* pBegin;
  std::cout<<"Ying Liu....\n";
  std::cout<< str <<"\n";
  
  //reverse word
  while(pEnd!= end)
  {
    if(*pEnd==' ')
	{
	  char* ppEnd = pEnd--;
	  Reverse(pBegin, ppEnd);
	  pBegin = pEnd+1;
	}
    pEnd++;
  }
  
  Reverse(pBegin, pEnd);
  
  std::cout<< str;
}