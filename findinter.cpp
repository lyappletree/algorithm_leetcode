#include <vector>

vector<int> findinter(int array1[], int len1, int array2[], int len2)
{
  vector<int> result;
  
  int i =0; 
  int j=0;
  
  while(i!=len1 && j!=len2)
  {
     if(array1[i]== array2[j])
	   {
	     result.push_back(array1[i]);
		 i++;
		 j++;
	   }
	 else if(array1[i]< array2[j])
	    i++;
	 else
	    j++;
  }
  
  return result;
}

int main()
{
  int array1[5] = {1,4,7,10,13};
  int array2[5] = {1,3,5,7,9};
  
  vector<int> result = findinter(array1, 5, array2, 5);
  
  for(vector<int>::iterator it = result.begin(); it!=result.end(); it++)
    std::cout<<*it<<" ";
}