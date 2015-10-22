#include <iostream>
#include <stddef.h>

void print(int **matrix, int rows, int cols)
{
  for (int i=0; i<rows; i++)
   {
     for (int j=0; j< cols; j++)
	    std::cout<< matrix[i][j] <<" ";
	 std::cout<<"\n";
   }
}

int getGift(int **matrix, int rows, int cols)
{
  int gift[rows][cols];
  for(int i=0; i< rows; i++)
     for(int j=0; j< cols; j++)
	   gift[i][j] = 0;
  
  for (int i=0; i< rows; i++)
     for (int j=0; j< cols; j++)
	   {
	      int tmp1 = 0;
		  int tmp2 = 0;
	      if (j-1 <0)
		     tmp1 = matrix[i][j];
		  else
		     tmp1 = gift[i][j-1] + matrix[i][j];
		  if (i-1<0)
		     tmp2 = matrix[i][j];
		  else
		     tmp2 = gift[i-1][j] + matrix[i][j];
		  if (tmp1>= tmp2)
		     gift[i][j]= tmp1;
		  else
		     gift[i][j] = tmp2;
	   }
	   
	return gift[rows-1][cols-1];
}

int main()
{
  int matrix_1[4][4] = {1, 10, 3, 8, 12, 2, 9, 6, 5, 7, 4, 11, 3, 7, 16, 5};
  
  int **matrix = new int *[4];
  for (int i=0; i< 4; i++)
     matrix[i] = new int [4];
	 
  for (int i=0; i< 4; i++)
     for (int j=0; j<4; j++)
	    matrix[i][j] = matrix_1[i][j];
  print(matrix, 4, 4);
  
  int gift = getGift(matrix, 4, 4);
  
  std::cout<<gift; 

}







