#include<iostream>
#include<vector>
#include<algorithm>

void print(vector<vector<int> > results)
{

  for(int i=0; i< results.size(); i++)
  {
    for(int j = 0; j<5; j++)
	  std::cout<< results[i][j]<<" ";
	std::cout<<"\n";
  }
  
}

vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > results;
        if (n==0 || k == 0)
           return results;
           
        if (k>n)
          return results;
        
        for(int i= 1; i<10; i++)
        {
            // std::cout<<"k-1.........."<< k-1 <<"......n-i....."<< n-i <<"....i....."<< i <<"\n";
			if (n-i>0)
			{
				vector<vector<int> > results_tmp = combinationSum3(k-1, n-i);
				int size1 = results_tmp.size();
				std::cout<<"results...size...."<< results.size() <<"\n";
				for (int i=0; i< size1; i++)
				{
					results_tmp[i].push_back(i);
					sort(results_tmp[i].begin(), results_tmp[i].end());
					results.push_back(results_tmp[i]);
				}
			}
			else if(k-1==0 && n-i == 0)
			{
				  vector<int> tmp;
				  tmp.push_back(i);
				  results.push_back(tmp);
				  print(results);
				  return results;
			}
        }

        unique(results.begin(), results.end());
        return results;
        
}

int main()
{
  vector<vector<int> > results = combinationSum3(2, 9);
  // std::cout<<"results...size...."<< results.size() <<"\n";
}