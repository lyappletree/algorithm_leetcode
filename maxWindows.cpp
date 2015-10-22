    #include <iostream>
	#include <vector>
	
	void printQueue(vector<int>& myqueue)
    {
        std::cout<<"print queue........\n";
        for(vector<int>::iterator it = myqueue.begin(); it!= myqueue.end(); it++)
           std::cout<<*it <<" ";
        std::cout<<"\n";
          
    }
    int getMax(vector<int>& myqueue)
    {
        printQueue(myqueue);
        int max = -1000;
        for(vector<int>::iterator it = myqueue.begin(); it!= myqueue.end(); it++)
              if (max<=*it)
                 max = *it;
        return max;
    }
	
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        int size1 = nums.size();
        vector<int> myqueue;
        
        if (k<=0 || size1 == 0)
           return results;
        
        int max = -1000;
        for(int i=0; i<k; i++)
         {
             myqueue.push_back(nums[i]);
             if (max <= nums[i])
                max = nums[i];
         }
         results.push_back(max);
         
         for (int i=k; i< size1; i++)
         {
             int tmp = myqueue[0];
             myqueue.erase(myqueue.begin());
             myqueue.push_back(nums[i]);
             std::cout<<"tmp........."<< tmp <<"\n";
             printQueue(myqueue);
             if (tmp==max)
             {
                 max = getMax(myqueue);
                 results.push_back(max);
             }
			 else if (nums[i]> max)
			 {
			    max = nums[i];
				results.push_back(max);
			 }
             else
                 results.push_back(max);
             
         }
        return results;
    }
	
	int main()
	{
	  std::vector<int> nums;
	  nums.push_back(1);
	  nums.push_back(3);
	  nums.push_back(-1);
	  nums.push_back(-3);
	  nums.push_back(5);
	  nums.push_back(3);
	  nums.push_back(6);
	  nums.push_back(7);
	  std::vector<int> results = maxSlidingWindow(nums, 3);
	  printQueue(results);
	  return 1;
	}