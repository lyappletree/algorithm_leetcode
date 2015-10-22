#include <math.h> 
#include <iostream>
#include <stddef.h>
#include <stack>

struct binaryTreeNode
{
  int m_value;
  binaryTreeNode* m_left;
  binaryTreeNode* m_right;
  binaryTreeNode(int value)
  {
    this->m_value = value;
	this->m_left = NULL;
	this->m_right = NULL;
  };
};

binaryTreeNode* insertNode(binaryTreeNode* root, int value)
{
   if (root == NULL)
    {
	  binaryTreeNode* root = new binaryTreeNode(value);
	  return root; 
	}
   else if (root->m_value > value)  
    {
      binaryTreeNode* left = insertNode(root->m_left, value);
	  root->m_left = left;
	}
   else
    {
      binaryTreeNode* right = insertNode(root->m_right, value);  
	  root->m_right = right; 
    }	  
}

binaryTreeNode* BuildTree(int a[], int length, int root_index)
{
   int root_value = a[root_index];
   binaryTreeNode* root = new binaryTreeNode (root_value);
   for (int i=0; i<length; i++)
   {
      if(i!= root_index)
	    insertNode(root, a[i]);
   }
   return root;
}

void printTree(binaryTreeNode* root)
{
   /* if (root==NULL)
     return;

   printTree(root->m_left);
   std::cout<<root->m_value<<" ";
   printTree(root->m_right);*/
   
   /* stack<int> mystack;
   binaryTreeNode * node = root;
   while (node!=NULL)
    { 
      if (node->m_right!=NULL)	  
	     mystack.push(node->m_right->m_value);
	  mystack.push(node->m_value);
	  node = node->m_left;
	  
	}
   while(!mystack.empty())
    {
	  int val = mystack.top();
	  std::cout<< val <<" ";
	  mystack.pop();
	}
  node = root->m_right;
  while (node!= NULL)
    {
	  mystack.push(node->m_value);
	  if (node->m_left!=NULL)
	      mystack.push(node->m_left->m_value);
	  node = node->m_right;
	}
  while(!mystack.empty())
   {
      int val = mystack.top();
	  std::cout<< val <<" ";
	  mystack.pop();
   }*/
   
   stack<binaryTreeNode*> mystack;
   binaryTreeNode* node = root;
   while(node!=NULL)
   {
     mystack.push(node);
	 node = node->m_left;
   }
   while(!mystack.empty())
   {
      node = mystack.top();
	  mystack.pop();
	  std::cout<<node->m_value <<" ";
	  if(node->m_right!=NULL)
	  {
	     node = node->m_right;
		 while(node!=NULL)
		 {
		   mystack.push(node);
		   node = node->m_left;
		 }
	  }
   }
   
}

int main()
{
   int a[11] = {14, 21, 24, 25, 28, 31, 32, 36, 39, 41, 47};
   binaryTreeNode* tree = BuildTree(a, 11, 5);
   printTree(tree);
   /* binaryTreeNode* node1 = new binaryTreeNode (31);
   binaryTreeNode* node2 = new binaryTreeNode (25);
   binaryTreeNode* node3 = new binaryTreeNode (36);
   binaryTreeNode* node4 = new binaryTreeNode (21);
   binaryTreeNode* node5 = new binaryTreeNode (28);
   binaryTreeNode* node6 = new binaryTreeNode (32);
   binaryTreeNode* node7 = new binaryTreeNode (41);
   
   node1->m_left = node2;
   node2->m_left = node4;
   node2->m_right = node5;
   node1->m_right = node3;
   node3->m_left = node6;
   node3->m_right = node7;
   
   printTree(node1);*/
   
  return 1;
}