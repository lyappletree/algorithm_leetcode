    #include <iostream>
	#include <vector>
	
    int hIndex(vector<int>& citations) {
        int size1 = citations.size();
        
        if (size1==0)
          return 0;
          
        if (size1 == 1 && citations[0]!=0)
          return 1;
          
        if (size1 == 1 && citations[0]==0)
          return 0;
          
        int i = 0;
        int j = size1-1;
        
        while(i<j)
        {
            int mid = i+ (j-i)/2;
            
            if (citations[mid] == size1-mid)
               return citations[mid];
            if (citations[mid] < size1-mid)
            {
              i= mid+1;
			  std::cout<<"i......"<<i <<"...j..."<< j <<"\n";
            }
            else if (citations[mid] > size1-mid && citations[mid-1]< size1-mid-1)
            {
              return size1-mid;
            }
            else
            {
              j = mid;
			  std::cout<<"j......"<<j <<"...i...."<<i <<"\n";
            }
        }
        
        if (citations[i]>= size1-i)
           return size1-i;
        else 
           return 0;

    }
	
	int main()
	{
	  vector<int> citations;
	  citations.push_back(0);
	  citations.push_back(0);
	  citations.push_back(1);
	  std::cout<< hIndex(citations)<<"\n";
	}
	
	