#include <iostream>
#include <map>
#include <vector>

vector<int> twoSum(vector<int>& nums, int target) {
   
    map<int, int> mymap;
	map<int, int>::iterator it2;
    vector<int>::iterator it;
	vector<int> results;
	int index = 1;
    for(it= nums.begin(); it!=nums.end(); it++)   
	  {
		   it2 = mymap.find(*it);
		   if(it2== mymap.end())
		      mymap[target-*it] = index;
		   else
		    {
			   results.push_back(it2->second);
			   results.push_back(index);
			   return results;
			}
		 
		 index++;
	  }
}

int main()
{
  vector<int> nums;
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(11);
  nums.push_back(15);
  int target = 9;
  vector<int> m = twoSum(nums, target); 
  std::cout<<m[0]<<" "<<m[1]<<"\n";
  return 1;
}