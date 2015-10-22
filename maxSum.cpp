#include <vector>

int main(int argc, char** argv)
{
   std::vector<int> matrix;
   int rows = 4;
   int cols = 4;
   matrix.push_back(1);
   matrix.push_back(10);
   matrix.push_back(3);
   matrix.push_back(8);
   matrix.push_back(12);
   matrix.push_back(2);
   matrix.push_back(9);
   matrix.push_back(6);
   matrix.push_back(5);
   matrix.push_back(7);
   matrix.push_back(4);
   matrix.push_back(11);
   matrix.push_back(3);
   matrix.push_back(7);
   matrix.push_back(16);
   matrix.push_back(5);
   std::vector<int> sumv;
   
   for (int i =0; i< 16; i++)
      sumv.push_back(0);
   
   std::cout<< "Ying Liu...1\n"; 
   sumv[0] = matrix[0];
   for (int x=0; x<rows; x++)
      for (int y=0; y<cols; y++)
	   {
	     if ((sumv[x*cols+y]+ matrix[x*cols+y+1])>= sumv[x*cols+y+1])
		   {
	        sumv[x*cols+y+1] = sumv[x*cols+y]+ matrix[x*cols+y+1];
			std::cout<< "Ying Liu...2"<<" "<<x <<" "<<y<<" "<<sumv[x*cols+y] <<" "<<matrix[x*cols+y+1] <<" "<<sumv[x*cols+y+1]<<" "<<x*cols+y+1 <<"\n"; 
		   }
	     if ((sumv[x*cols+y]+ matrix[(x+1)*cols+y]) >= sumv[(x+1)*cols+y])
		   {
		    
		    sumv[(x+1)*cols+y] = sumv[x*cols+y]+ matrix[(x+1)*cols+y];
			std::cout<< "Ying Liu...3"<<" "<<x <<" "<<y <<" "<< sumv[x*cols+y]<<" "<< matrix[(x+1)*cols+y]<<" "<<sumv[(x+1)*cols+y]<<" "<<(x+1)*cols+y <<"\n"; 
		   }
	    }
   std::cout<< sumv[rows*cols-1] <<"\n"; 
    for (int x=0; x<rows; x++)
      for (int y=0; y<cols; y++)
       	  std::cout<<sumv[x*cols+y]<<" "; 
   return sumv[rows*cols-1];
}










