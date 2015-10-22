#include<string>
#include<stack>
#include<iostream>

struct Position
{
  int x;
  int y;
};

void printMatrix(char** mtx, int row, int col)
{
  for(int i=0; i< row; i++)
  {
    for(int j=0; j< col; j++)
	  std::cout<<mtx[i][j]<<" ";
	std::cout<<"\n";
  }
}

Position findBegin(char** mtx, int** visited, int row, int col, char a)
{
    Position p;
	p.x = -1;
	p.y = -1;
	std::cout<<"a......."<<a<<"\n";
	printMatrix(mtx, row, col);
	
    for(int ii=0; ii<row; ii++)
	{
	  for(int jj=0; jj<col; jj++)
	  {
	    if(a== mtx[ii][jj]&& visited[ii][jj]==0)
		   {
			 p.x = ii;
			 p.y = jj;
		   }
	  }
	}
	
	return p;
}

stack<Position> findString(string str, int row, int col, char** mtx)
{
  Position up = {0, -1};
  Position right = {1, 0};
  Position down = {0, 1};
  Position left = {-1,0};
  Position dir[] = {up, right, down, left};
 
  int **visited;
  visited = new int *[row];
  for(int i = 0; i <row; i++)
    visited[i] = new int[col];
	
  // int visited[row][col];
  for(int i=0; i<row; i++)
  {
    for(int j=0; j<col; j++)
	  visited[i][j]=0;
  }
  
  stack<Position> path;
  
  int len = str.length();
  Position m = findBegin(mtx, visited, row, col, str[0]);
  if( m.x!=-1 && m.y!=-1)
    path.push(m);
	
  std::cout<<"Ying Liu.....1..."<<path.empty()<<"\n";
  for(int i=1; i<len; i++)
  {    std::cout<<"Ying Liu.....2\n";
    bool flag = false;
    Position mm = path.top();
    for(int j=0; j<4; j++)
	   {
		 int x = mm.x+ dir[j].x;
		 int y = mm.y+ dir[j].y;
		 std::cout<<"Original_x...."<<mm.x<<"...Original_y..."<< mm.y<<"\n";
		 std::cout<<"x...."<<x<<"...y..."<< y<<"\n";
		 if(x>=0&& x< row && y>=0 && y< col && visited[x][y] == 0 && str[i]==mtx[x][y])
		    {    std::cout<<"Ying Liu.....3\n";
			   Position tmp;
			   tmp.x = x;
			   tmp.y = y;
			   path.push(tmp);
			   visited[x][y] = 1;
			   flag = true;
			   
			   cout<<"i....."<<i<<"...str[i]..."<<str[i]<<"\n";
			}
         std::cout<<"j....."<<j<<"\n";			
	   }
	 std::cout<<"Ying Liu....7\n";
	 if(flag==false && !path.empty())
	  {  std::cout<<"Ying Liu....6\n";
	    Position mn = path.top();
		path.pop();
		visited[mn.x][mn.y] =0;
		i--;
	  }
	if(path.empty())
	{
	  i = 1;
	  Position n = findBegin(mtx, visited, row, col, str[0]);
      if( n.x!=-1 && n.y!=-1)
      path.push(n);
	}
  }
  std::cout<<"Ying Liu....8\n";
  return path;
}


int main()
{
  char mm[3][4] = {'A', 'B', 'C', 'E', 'S', 'F', 'C', 'S', 'A', 'D', 'E', 'E'};
  string str = "EECCB"; 
  
  char **matrix;
  matrix = new char *[3];
  for(int i = 0; i <4; i++)
    matrix[i] = new char[4];
	
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<4; j++)
	  matrix[i][j] = mm[i][j];
  }
	
  stack<Position> pth = findString(str, 3, 4, matrix);
  while(!pth.empty())
  {
    Position tmp = pth.top();
    std::cout<<tmp.x<<" "<<tmp.y<<"\n";
	pth.pop();
  }

  return 1;
}