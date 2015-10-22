    #include <iostream>
	#include <vector>
	
	void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it;
		int size1 = nums.size();
		int count = 0;
        
        for (it = nums.begin(); it!= nums.end();)
        {  
		    if (count==size1)
			   return;
            if (*it == 0)
            {
                it = nums.erase(it);
                nums.push_back(0);
				// it++;
                std::cout<<"*it......"<< *it <<"\n";
            }
            else
              it++;
			count++;
        }
        return;
        
    }
	
	int main()
	{
	  vector<int> nums;
	  nums.push_back(0);
	  nums.push_back(1);
	  nums.push_back(0);
	  nums.push_back(3);
	  nums.push_back(12);
	  moveZeroes(nums);
	  
	  for (vector<int>::iterator it = nums.begin(); it!=nums.end(); it++)
	     std::cout<< *it <<" ";
	
	}