#include <iostream>
#include <stddef.h>
#include <string>
#include <stack>

struct Position
{
   int x;
   int y;
};

void print(char **matrix, int rows, int cols)
{
  for (int i=0; i<rows; i++)
   {
     for (int j=0; j< cols; j++)
	    std::cout<< matrix[i][j] <<" ";
	 std::cout<<"\n";
   }
}

bool hasPath(char **matrix, int rows, int cols, std::string str)
{
   print(matrix, rows, cols);
   
   Position up = {0, -1};
   Position right = {1, 0};
   Position down = {0, 1};
   Position left = {-1, 0};
   Position dir[] = {up, right, down, left};
   
   int visited[rows][cols]; 
   for (int i=0; i<rows; i++)
     for (int j=0; j< cols; j++)
        visited[i][j] = 0;
		
   for (int i=0; i<rows; i++)
     for (int j=0; j< cols; j++)
        std::cout<< visited[i][j] <<" ";
   std::cout<<"\n";

		
   
   std::stack<char> path;
   Position current = {0, 0};
   int k=0;
   
   //find the beginning of the string from matrix
   bool flag2 = false;
   for(int i=0; i< rows; i++)
    {
	 if (flag2 == false)
	 {
      for(int j=0; j< cols; j++)
	     if (matrix[i][j] == str[k])
		    {
			  path.push(str[k]);
			  current.x = i;
			  current.y = j;
			  visited[i][j] = 1;
			  flag2 = true;
			  k++;
			  break;
			}
	  }
	}
			
    // find a path
	while (k< str.length() && !path.empty())
	{
	   bool flag = false;
	   for (int n=0; n< sizeof(dir)/sizeof(Position); n++)
	     {
		    int tmp_x = current.x+dir[n].x;
			int tmp_y = current.y-dir[n].y;
			if (tmp_x>=0 && tmp_x<3 && tmp_y>=0 && tmp_y<4 && matrix[tmp_x][tmp_y] == str[k] && visited[tmp_x][tmp_y]==0)
			   {  		
			      path.push(str[k]);
				  visited[tmp_x][tmp_y] = 1;
				  current.x = tmp_x;
				  current.y = tmp_y;
				  k++;
				  flag =true;
				  break;
			   }
			
		 }
	   if(flag == false)
	      path.pop();
	}
   if (path.empty())
     return false;
   else
     return true;
}

int main()
{
  char matrix_1[3][4]= {'A', 'B', 'C', 'E', 'S', 'F', 'C', 'S', 'A', 'D', 'E', 'E'};
  
  char **matrix;
  matrix = new char *[3];
  for (int i=0; i<3; i++)
     matrix[i] = new char[4];
  for (int i=0; i<3; i++)
     for (int j=0; j<4; j++)
	    matrix[i][j] = matrix_1[i][j];

  bool has = hasPath(matrix, 3, 4, "CESE");
  std::cout<< has;
}