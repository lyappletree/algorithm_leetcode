#include <iostream>
#include <stddef.h>
#include <vector>

struct coordinates
{
  int left;
  int right;
  int height;
};

struct point
{
  int left;
  int height;
};

int getMin(int num1, int num2)
{
  if (num1 <= num2)
     return num1;
  else
     return num2;
}


vector<point> getSkyline(std::vector<coordinates> coo)
{
   std::vector<point> skyline;
   int current_height = 0;
   std::vector<coordinates>::size_type sz = coo.size();
   int L1, R1, h1, L2, R2, h2;
   point m_point;
  std::cout<< "sz....." <<sz<<"\n";
   // for (std::vector<coordinates>::iterator it = coo.begin(); it!= coo.end(); it++)
   for (int i=0; i< (sz-1); i++)
   {
      L1 = coo[i].left;
      R1 = coo[i].right;	
      h1 = coo[i].height;
  
      L2 = coo[i+1].left;
      R2 = coo[i+1].right;
      h2 = coo[i+1].height;	  
	  
	  std::cout<< L1 <<" "<< R1 <<" "<<h1<<"\n";
	  std::cout<< L2 <<" "<< R2 <<" "<<h2<<"\n";
	  if (L1 < L2 && current_height!= h1 && R1>L2)
	  {
	      std::cout<<"Ying Liu.....1..R1..."<< R1 <<"...L2..." << L2<<"\n";
		  current_height = h1;
		  m_point.left = L1;
		  m_point.height = h1;
	  }
	  else if(L1 == L2 && current_height!= getMin(h1, h2))
	  {  std::cout<<"Ying Liu.....2\n";
	    current_height = getMin(h1, h2);
		m_point.left = L1;
		m_point.height = current_height;
	  }
	  else if(R1>= L2 && current_height!=h2)
	  { std::cout<<"Ying Liu.....3\n";
	    current_height = h2;
		m_point.left = R1;
		m_point.height = current_height;
	  }
	  else if(R1< L2)
	  { std::cout<<"Ying Liu.....4\n";
	    current_height = 0;
		m_point.left = L2;
		m_point.height = current_height;
	  }
	  
	  std::cout<< m_point.left <<" "<< m_point.height <<"\n";
	  skyline.push_back(m_point);
   }
   point data;
   if (R1 > R2)
	 data.left = R1;
   else
     data.left = R2;    	  
   data.height = 0;
   skyline.push_back(data);
   
   return skyline;
}

void printVectorData(std::vector<point> v_data)
{
  std::cout<<"print vector....\n";
  for (std::vector<point>::iterator it = v_data.begin(); it!= v_data.end(); it++)
    std::cout<<it->left<<" "<< it->height <<"\n";
}


int main()
{
  int m_data[5][3] = {2,9,10,3,7,15,5,12,12,15,20,10,19,24,8};
  std::vector<coordinates> coo;
  
  for (int i=0; i<5; i++)
  {
		  coordinates data;
		  data.left = m_data[i][0];
		  data.right = m_data[i][1];
		  data.height = m_data[i][2]; 
		  coo.push_back(data);
  }
  vector<point> m = getSkyline(coo);
  
  printVectorData(m);
}