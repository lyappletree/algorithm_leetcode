#include <iostream>
#include <stddef.h>
#include <map>
#include <stack>

void print(int **matrix, int rows, int cols)
{
  for (int i=0; i<rows; i++)
   {
     for (int j=0; j< cols; j++)
	    std::cout<< matrix[i][j] <<" ";
	 std::cout<<"\n";
   }
}

struct Position
{
   int x;
   int y;
};

bool hasfirstOnes(int **matrix, int rows, int cols, Position& current)
{
   bool has = false;
   // Position current;
   bool flag = false;
   for (int i=0; i< rows; i++)
     for (int j=0; j< cols; j++)
	    if (matrix[i][j] == 1)
		  {
		    if (flag == false)   // find the first 1
			 {
			   current.x = i;
			   current.y = j;
			   flag = true;
			   has = true;
			 }
		  }
    return has;  
}

int findGroups(int **matrix, int rows, int cols)
{

   Position up = {0, -1};
   Position right = {1, 0};
   Position down = {0, 1};
   Position left = {-1, 0};
   Position dir[] = {up, right, down, left};
   Position current;
   
   std::stack<Position> path;
   int group = 0;
   while(hasfirstOnes(matrix, rows, cols, current))
    {  std::cout<< "1x...."<< current.x<<"...y..." << current.y<<"\n";
	   path.push(current);
       matrix[current.x][current.y] = 0;
	   while(!path.empty())
	   {
	   bool flag = false;
	   for (int n=0; n< sizeof(dir)/sizeof(Position); n++)
	     {
		    int tmp_x = current.x+dir[n].x;
			int tmp_y = current.y-dir[n].y;
			std::cout<< "tmp_x ...."<< tmp_x <<"...tmp_y..." << tmp_y<<"\n";
			if (tmp_x>=0 && tmp_x< rows && tmp_y>=0 && tmp_y<cols && matrix[tmp_x][tmp_y] == 1)
			   {  
                  Position tmp = {tmp_x, tmp_y};			   
			      path.push(tmp);
				  matrix[tmp_x][tmp_y] = 0;
				  current.x = tmp_x;
				  current.y = tmp_y;
				  std::cout<< "2x...."<< current.x<<"...y..." << current.y<<"\n";
				  flag =true;
				  break;
			   }
			
		 }
	   if(flag == false)
	    { std::cout<< "Ying LIu....\n";
	      path.pop();
		  if (!path.empty())
		    current = path.top();
		}
		}
		group++;
		std::cout<<"group........" << group<<"\n";
	}
    return group;
}

int main()
{
  int matrix_1[4][5] = {1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0 , 0, 1, 0, 0};
  
  int **matrix = new int *[4];
  for (int i=0; i< 4; i++)
     matrix[i] = new int [5];
	 
  for (int i=0; i< 4; i++)
     for (int j=0; j<5; j++)
	    matrix[i][j] = matrix_1[i][j];
  print(matrix, 4, 5); 
  
  int group = findGroups(matrix, 4, 5);
  std::cout<< group; 
}