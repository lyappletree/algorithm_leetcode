#include <iostream>
#include <vector>

int binarySearch(vector<int>& nums, int& i, int& j)
    {
	    std::cout<<"i...."<< i <<"\n";
		std::cout<<"j...."<< j <<"\n";
        int size1 = nums.size();
		std::cout<<"size1........" << size1 <<"\n";
     
		if (j-i == 0)
		  return nums[i];
        
        int mid = i+(j-i)/2;
        
        while(i<j)
        {
            if (nums[mid] >nums[i] && nums[mid]<nums[j])
            {  std::cout<<"Ying Liu.....1.......\n";
               int right = mid-1;
               return binarySearch(nums, i, right);
            }
			if (nums[mid]<nums[i] && nums[mid]<nums[j])
			{  std::cout<<"Ying Liu.....8.......\n";
			   // int left = i+1;
			   int right = mid;
			   // return binarySearch(nums, left, j);
			   return binarySearch(nums, i, right);
			}
            if (nums[mid]>nums[i] && nums[mid]>nums[j])
            {  std::cout<<"Ying Liu.....2.......\n";
               return binarySearch(nums, mid, j);
            }
            if (nums[mid] == nums[i] && nums[mid]<nums[j])
            {  std::cout<<"Ying Liu.....3.......\n";
               return nums[mid];
            }
            if (nums[mid]==nums[j] && nums[mid]> nums[i])
            {  std::cout<<"Ying Liu.....4.......\n";
               return nums[i];
            }
            if (nums[mid]==nums[j] && nums[mid]> nums[i])
            {  std::cout<<"Ying Liu.....5.......\n";
               return nums[i];
            }
			if (nums[mid] == nums[i] && nums[mid]>nums[j])
            {  std::cout<<"Ying Liu.....6.......\n";
               return nums[j];
            }
        }
        return i;
        
    }
	
    int main()
	{
	    vector<int> nums;
		nums.push_back(3);
		nums.push_back(1);
		nums.push_back(2);
	    int size1 = nums.size();
        if (size1 == 0)
          return 0;
        int right = size1-1;
        int left = 0;
        std::cout<< binarySearch(nums, left, right);
		
		return 1;
	
	}