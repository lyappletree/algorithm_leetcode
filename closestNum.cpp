#include <stddef.h>
#include <iostream>
#include <vector>
#include <stack>

struct sumNode
{
  int value1;
  int value2;
};

struct Tree
{
  int m_value;
  Tree* m_left;
  Tree* m_right; 
  Tree (int value){this->m_value = value; this->m_left = NULL; this->m_right = NULL;};
};

int findClossest(Tree* root, int num)
{
  Tree* p = root;
  int min = 100;
  int number = 500;
  while(p!=NULL)
  {
    if(num == p->m_value)
	   return p->m_value;
	else if(num < p->m_value)
	  {
	    int tmp = p->m_value - num;
		if(min> tmp)
		 {
		   min = tmp;
		   number = p->m_value;
		 }
	    p = p->m_left;
	  }
	else
	  {
	    int tmp = num - p->m_value;
		if(min > tmp)
		{
		   min = tmp;
		   number = p->m_value;
		}
	    p = p->m_right;
	  }
  }
  return number;
}

vector<sumNode> findSum(Tree* root, int sum)
{
  vector<sumNode> result;
  Tree* p = root;
  stack<Tree*> left_stack;
  stack<Tree*> right_stack;
  while(p!=NULL)
  {
    left_stack.push(p);
	p = p->m_left;
  }
  p = root;
  while(p!=NULL)
  {
    right_stack.push(p);
	p = p->m_right;
  }
  
  Tree* pre = left_stack.top();
  left_stack.pop();
  
  Tree* post = right_stack.top();
  right_stack.pop();
  
  
  while(!right_stack.empty()&& !left_stack.empty())
  {
    std::cout<<"Ying Liu......9\n";
     int num2 = pre->m_value + post->m_value;
    if (num2< sum)
	{  std::cout<<"Ying Liu......1\n";
      pre = left_stack.top();
	  left_stack.pop();
	  Tree* pl = pre->m_right;
	while (pl!=NULL)
	 { 
          left_stack.push(pl);
		  pl = pl->m_left;
	 }
	}
	else if(num2 == sum)
	{   std::cout<<"Ying Liu......2\n";
	  sumNode t;
	  t.value1 = pre->m_value;
	  t.value2 = post->m_value;
	  result.push_back(t);
	  std::cout<<"Ying Liu......4\n";
	  Tree* pl = pre->m_right;
	  while (pl!=NULL)
	  { 
          left_stack.push(pl);
		  pl = pl->m_left;
	  }	 
      pre = left_stack.top();
	  left_stack.pop();
std::cout<<"Ying Liu......5\n";
	  Tree* pr = post->m_left;
	  while(pr!=NULL)
	  {
	    right_stack.push(pr);
	    pr = pr->m_right;
	  }	 

std::cout<<"Ying Liu......6\n"; 	  
      post = right_stack.top();
std::cout<<"Ying Liu......7\n";
	  right_stack.pop();
std::cout<<"Ying Liu......8\n";	  
	}
	else {  std::cout<<"Ying Liu......3\n";
      post = right_stack.top();
	  right_stack.pop();
	  Tree* pr = post->m_left;
	  while(pr!=NULL)
	  {
	    right_stack.push(pr);
	    pr = pr->m_right;
	  }
	}
  }
  return result;
}

int main()
{
  // build a binary tree 
  Tree* node32 = new Tree(32);
  Tree* node24 = new Tree(24);
  Tree* node41 = new Tree(41);
  Tree* node21 = new Tree(21);  
  Tree* node28 = new Tree(28);
  Tree* node36 = new Tree(36);
  Tree* node47 = new Tree(47);
  Tree* node14 = new Tree(14);
  Tree* node25 = new Tree(25);
  Tree* node31 = new Tree(31);
  Tree* node39 = new Tree(39);
  
  node32->m_left = node24;
  node32->m_right = node41;
  
  node24->m_left = node21;
  node24->m_right = node28;
  
  node41->m_left = node36; 
  node41->m_right = node47;
  
  node21->m_left = node14;
  
  node28->m_left = node25;
  node28->m_right = node31;
  
  node36->m_right = node39;
  
  int a = findClossest(node32, 29);

  std::cout<< a;   
  
  vector<sumNode> bb = findSum(node32, 66);
  
  for(vector<sumNode>::iterator it= bb.begin(); it!=bb.end(); it++)
    std::cout<< (*it).value1<<" "<< (*it).value2;
}