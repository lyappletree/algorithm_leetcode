#include <stdio.h>
#include <vector>
std::vector<int> merge(std::vector<int> tmp, int left, int right, int size)
{
  int mid_length = size/2;
  /* merge process */
  std::vector<int> store;
  int i = 0;
  int j = i+ mid_length;
  while ( i<mid_length && j<= right)
   {  
	  if(tmp[i+left] > tmp[j+left])
	   {  
	     store.push_back(tmp[j+left]);
		 j++;
	   }
	  else
	   {
	     store.push_back(tmp[i+left]);
		 i++;
	   }
   }
   /* for non-empty queue when the other queue is empty*/
   if (i<mid_length)
     while(i<mid_length)
	 {
	   store.push_back(tmp[i+left]);
	   i++;
	 }
   if (j<= right)
     while(j<= right)
	 {
	   store.push_back(tmp[j+left]);
	   j++;
	 }

  for (int i=left; i<=right; i++)
     tmp[i] = store[i-left];
  return tmp;
}

int main()
{
  int mm[8] = {10,3,2,6,1,9,5,4}; 
  std::vector<int> m(&mm[0], &mm[0]+8);
  /* bottom up process */
  for(int size =2; size<= m.size(); )
   {
	  for(int left = 0; left < 8;) 
	   {  
		 m = merge(m,left, left+size-1,size);
		 left = left+size;
	   }
   /* print sorted array after comparing each small group*/   
   std::vector<int>::iterator it;
   for (it= m.begin(); it!=m.end(); it++)
      std::cout<<*it<<" "; 
   std::cout<<"\n"; 
	  
	 size = size*2;
   }
   return -1;
}