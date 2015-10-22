    #include<iostream>
    #include<vector>
	int minPathSum(vector<vector<int> >& grid) {
        
        int size1 = grid.size();
        int size2 = grid[0].size();
        if (size1 == 0)
           return 0;
           
        int results[size1][size2];
        for (int m=0; m<size1; m++)
        {
            for (int n=0; n< size2; n++)
            {
                results[m][n] = 0;
            }
        }
        
        results[0][0] = grid[0][0];
        if (size1 == 1)
          return results[0][0];
          
        for(int i=1; i< size2; i++) 
        {
          results[0][i] = grid[0][i]+ results[0][i-1];
        }
		std::cout<<"Ying Liu...2....."<<"\n";
        std::cout<<"Ying Liu...1....."<<results[0][3]<<"\n"; 
        for(int j=1; j< size1; j++) 
        {
          results[j][0] = grid[j][0]+ results[j-1][0];
        }
        for (int m=1; m<size1; m++)
        {
            for (int n=1; n< size2; n++)
            {
                int tmp1;
                int tmp2;
               
                    tmp1 = grid[m][n] + results[m-1][n];
                    tmp2 = grid[m][n] + results[m][n-1];
                    results[m][n] = min(tmp1, tmp2);
            }
        }
        for (int i = 0; i< size1; i++)
        {
            for (int j = 0; j< size2; j++)
            {
                std::cout<< results[i][j];
            }
            std::cout<<"\n";
        }
        
       
        return results[size1-1][size2-1];
        
    }
	
	int main()
	{ 
	   vector<vector<int> > input;
	   vector<int> tmp;
	   tmp.push_back(9);
	   tmp.push_back(1);
	   tmp.push_back(4);
	   tmp.push_back(8);
	   input.push_back(tmp);
	   
	   std::cout<<minPathSum(input);
	}