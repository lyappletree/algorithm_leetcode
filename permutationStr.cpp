#include <stddef.h>
#include <iostream>

void PermutationCore(char* pStr, char* pBegin)
{
   char* pCh = NULL;
   char temp;
   if(*pBegin == '\0')
   {
      std::cout<<pStr<<"\n";
   }
   else
   {
      for(pCh = pBegin; *pCh!='\0'; ++pCh)
	   {
	      temp = *pCh;
		  *pCh = *pBegin;
		  *pBegin = temp;
		  
		  PermutationCore(pStr, pBegin+1);
		  
		  temp = *pCh;
		  *pCh = *pBegin;
		  *pBegin = temp;
	   }
   }
}

void Permutation(char* pStr)
{
   if(pStr== NULL)
      return;
   PermutationCore(pStr, pStr);
}

int main(int argc, char** argv)
{
  Permutation("abc");
  return 1;
}