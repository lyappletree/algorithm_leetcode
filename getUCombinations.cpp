#include <vector>
#include <iostream>

bool noswap(int k, int i, const vector<int> num)
{
   for (int j=k; j<i; j++)
   {
     if (num[j]== num[i])
	    return true;
   }
   return false;
}

void perm (vector<int> num, int k, int n, vector<vector<int> > &res)
{
   if (k==n){res.push_back(num);}
   else
   {
      for (int i=k; i<=n; i++)
	   {
	     if (noswap(k,i,num)){continue;}
		 int tmp = num[k];
		 num[k] = num[i];
		 num[i] = tmp;
		 
		 perm (num, k+1, n, res);
		 
		 tmp = num[k];
		 num[k] = num[i];
		 num[i] = tmp;
	   }
   }
}

int main()
{
 int data[5] = {1, 2, 2, 4, 2};
 vector<int> num(&data[0], &data[0]+5);
 vector<vector<int> > res;
 perm(num, 0, (num.size()-1), res);
 for(std::vector<vector<int> >::iterator it = res.begin(); it!= res.end(); it++)
 {
   std::vector<int> m = *it;
   for(std::vector<int>::iterator p = m.begin(); p!=m.end(); p++)
    {
	  std::cout<<*p;
	}
   std::cout<<"\n";
 }
}