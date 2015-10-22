#include<iostream>
#include <stddef.h>

struct BinaryTreeNode
{
  int m_value;
  BinaryTreeNode* m_left;
  BinaryTreeNode* m_right;
  BinaryTreeNode(int value){this->m_value = value; m_left=NULL; m_right=NULL;};
};

bool verifyPost(int sequence[], int length)
{

  std::cout<<"length......"<<length<<"\n";
  if (length<=0)
    return false;
  
  int root = sequence[length-1];
  std::cout<<"root........2"<<root<<"\n";
  int i=0;
  for(; i<length-1; i++)
  {  std::cout<<"sequence[i]........"<< sequence[i] <<"\n";
    if(sequence[i]> root)
	  break;
  }
  int j =i;
  for(;j<length-1;j++)
  {  std::cout<<"sequence[j]........"<<sequence[j]<<"\n";
    if(sequence[j]<root)
	  return false;
  }
  
  bool left = false;
  if(i>0)
    left = verifyPost(sequence, i);
  bool right = false;
  
  if(i<length-1)
     right = verifyPost(sequence+i, length-i-1);
  std::cout<<"Ying Liu........5\n";
  return left && right;
}

bool isBSTCore(BinaryTreeNode* root, int min, int max)
{
  if(root==NULL)
    return true;
  if(root->m_value<min || root->m_value>max)
    return false;
  
  return isBSTCore(root->m_left, min, root->m_value)&&isBSTCore(root->m_right, root->m_value, max);
}

bool isBST(BinaryTreeNode* root)
{
  int min = -1000;
  int max = 1000;
  
  return isBSTCore(root, min, max);
}

int main()
{ 
  int sequence[7] = {5,7,6,9,11,10,18};
  std::cout<<"Ying Liu........1\n";
  std::cout<< verifyPost(sequence,7)<<"\n";
  
  BinaryTreeNode* node10 = new BinaryTreeNode(10);
  BinaryTreeNode* node6 = new BinaryTreeNode(6);
  BinaryTreeNode* node4 = new BinaryTreeNode(4);
  BinaryTreeNode* node8 = new BinaryTreeNode(8);
  BinaryTreeNode* node14 = new BinaryTreeNode(14);
  BinaryTreeNode* node12 = new BinaryTreeNode(12);
  BinaryTreeNode* node16 = new BinaryTreeNode(16);
  
  node10->m_left = node6;
  node10->m_right = node14;
  node6->m_left = node4;
  node6->m_right = node8;
  node14->m_left = node12;
  node14->m_right = node16;
  
  std::cout<< isBST(node10)<<"\n";
  
  return 1;
}