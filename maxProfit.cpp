    #include <vector>
	#include <iostream>
	
	
	int maxProfit(int k, vector<int> prices) {
        int n = prices.size();
        if(n==0)
           return 0;
        int current_price = prices[0];
        int profits[k][n];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
               profits[i][j]=0;
			   
		for(int i=0; i<k; i++)
		{
		  for(int j=0; j<n; j++)
		  {
		    std::cout<<profits[i][j]<<" ";
		  }
		  std::cout<<"\n";
		}
		
		for(int i=0; i<n; i++)
		  std::cout<< prices[i] <<" ";
		std::cout<<"\n";
		
        profits[0][0] = 0;
        profits[0][1] = 0;
        profits[1][0] = 0;
        if (prices[1]-prices[0]>0)
           profits[1][1] = prices[1]-prices[0];
               
        for(int i=1; i<k; i++)
        {
            for(int j=1; j<n; j++)
            {
                int tmp1 = 0;
				int tmp2 = 0;
                if(prices[j]-prices[j-1]>0)
                {
                   tmp1 = profits[i-1][j-1]+ prices[j]-prices[j-1];  // profits[i-1][j]
                   if(tmp1> profits[i-1][j])
                      profits[i-1][j] = tmp1;
				   tmp2 = profits[i][j-1]+ prices[j]-prices[j-1]; // profits[i][j]
				   profits[i][j] = tmp2;
                }
                else
                {
                   tmp1 = profits[i-1][j-1];         // profits[i][j], just buy, but no sell
				   tmp2 = profits[i][j-1];                     // profits[i][j], no buy
				   
				   if(tmp2> tmp1)
				     profits[i][j] = tmp2;
				   else
				     profits[i][j] = tmp1;
                }
            }
              
        }
		
		for(int i=0; i<k; i++)
		{
		  for(int j=0; j<n; j++)
		  {
		    std::cout<<profits[i][j]<<" ";
		  }
		  std::cout<<"\n";
		}
        
        return profits[k-1][n-1];
        
    }
	
	int main()
	{
	   vector<int> prices;
	   prices.push_back(1);
	   prices.push_back(3);
	   prices.push_back(4);
	   prices.push_back(5);
	   prices.push_back(6);
	   prices.push_back(8);
	   int m = maxProfit(2, prices);
	   std::cout<< m;
	}