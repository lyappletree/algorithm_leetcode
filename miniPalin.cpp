#include<string>

bool isPalin(string str2, int i, int j)
{
  while(i < j)
  {
    if (str2[i]!=str2[j])
	  return false;
	i++;
	j--;
  }
  return true;
}

void print(int** number, int len)
{
    for(int ii=0; ii<len; ii++)
	{
      for(int jj=0; jj<len; jj++)
	     std::cout<<number[ii][jj]<"Ying Liu";
	  std::cout<<"\n";
	}
}

void printSubStr(string str, int i, int j)
{
  for(;i<=j; i++)
    std::cout<< str[i];
  std::cout<<"\n";
}

int minSplit(string str)
{
     int len = str.length();
   int number[len][len];
   
	for (int i=0; i<len; i++)
	  for (int j=0; j<len; j++)
	     number[i][j] = 0;
		 
	std::cout<<"print matrix.......\n";	
	for (int i=0; i<len; i++)
	{
	  for (int j=0; j<len; j++)
	     std::cout<<number[i][j] <<" ";	
      std::cout<<"\n";
    }
   
  for(int i=0; i<len; i++)
    for(int j=0; j<len; j++)
	 {
	       bool flag = isPalin(str, i, j);
		   if (flag == true)
		     number[i][j]= 0;
		   else
		    {
				 int min = 200;
	             for(int k=i; k<j; k++)
	             {
			        int tmp = number[i][k] + 1 + number[k+1][j]; 
			
			        if (min> tmp)
			           min = tmp;
			     }
				   number[i][j] = min;
		    }
	 }
	 
   return number[0][len-1];
}

int splitmin2(string str)
{
  int len = str.length();
  int number[len];
  for (int i=0; i<len; i++)
  {
    bool flag = isPalin(str, 0, i);
	if (flag == true)
	   number[i] = 0;
	else
	 {
	    int min = 200;
	    for (int j=0; j<i; j++)
		{
		  if(isPalin(str, j+1, i))
		   {
		      int tmp = number[j]+1;
		      if (min > tmp)
			     min = tmp;
		   }
		}
		number[i] = min;
	 }
  }
  
  return number[len-1];
}

int main()
{
  string str= "abbab";
 /* int** number = new int*[len];
  for(int ii=0; ii<len; ii++)
    number[ii] = new int[len];
  for(int ii=0; ii<len; ii++)
    for(int jj=0; jj<len; jj++)
	  number[ii][jj]= 0;*/
	  

 // print(number, len);
  std::cout<< splitmin2(str);
  return 1;
}