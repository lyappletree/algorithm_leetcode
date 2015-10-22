// Convert a binary search tree to a sorted double-linked list. We can only change the target of pointers, but cannot create any new nodes. 
#include <iostream>
#include <stddef.h>
#include <stack>

struct BinaryTreeNode
{
  int m_value;
  BinaryTreeNode* m_left;
  BinaryTreeNode* m_right;
  BinaryTreeNode(int value)
  {
    this->m_value = value; 
	this->m_left = NULL; 
	this->m_right = NULL;
  };
};

BinaryTreeNode* buildDoubleLinked(BinaryTreeNode* root)
{
  if (root->m_left == NULL || root->m_right == NULL)
     return root;
  BinaryTreeNode* childr = buildDoubleLinked(root->m_left);
  std::cout<<"childr...." << childr->m_value<<"...root..."<<root->m_value<<"\n";
  childr->m_right = root;
  BinaryTreeNode* right = root->m_right;
  // std::cout<<"root->m_right..." << right->m_value <<"\n";
  BinaryTreeNode* childl = buildDoubleLinked(root->m_right); 
  std::cout<<"childl...." << childl->m_value<<"...root..."<<root->m_value<<"\n";
  childl->m_left = root;
    
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
  if(pNode == NULL)
     return;
  
  BinaryTreeNode *pCurrent = pNode;
  
  if(pCurrent->m_left!= NULL)
     ConvertNode(pCurrent->m_left, pLastNodeInList);
	 
  pCurrent->m_left = *pLastNodeInList;
  if(*pLastNodeInList != NULL)
     (*pLastNodeInList)->m_right = pCurrent;
  
  *pLastNodeInList = pCurrent;
  
  if(pCurrent->right!= NULL)
     ConvertNode(pCurrent->m_right, pLastNodeInList);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
  BinaryTreeNode* pLastNodeInList = NULL;
  ConvertNode(pRootOfTree, &pLastNodeInList);
  
  BinaryTreeNode *pHeadOfList = pLastNodeInList;
  while(pHeadOfList!=NULL && pHeadOfList->m_left!=NULL)
     pHeadOfList = pHeadOfList->m_left;
  
  return pHeadOfList;
}

void inOrderTraverse (BinaryTreeNode* root)
{
   if(root== NULL)
      return;
   inOrderTraverse(root->m_left);
   std::cout<<root->m_value<<" ";
   inOrderTraverse(root->m_right);
}


void printLinkedlist(BinaryTreeNode* head) 
{
   BinaryTreeNode* p;
   p = head;
   while ( p->m_left!=NULL)
   {
     std::cout<<p->m_value <<" ";
	 p = p->m_left; 
   }
}

int main( )
{
  // build a binaryTree
  BinaryTreeNode* root = new BinaryTreeNode(10);
  BinaryTreeNode* node6 = new BinaryTreeNode(6);
  BinaryTreeNode* node14 = new BinaryTreeNode(14);
  BinaryTreeNode* node4 = new BinaryTreeNode(4);
  BinaryTreeNode* node8 = new BinaryTreeNode(8);
  BinaryTreeNode* node12 = new BinaryTreeNode(12);
  BinaryTreeNode* node16 = new BinaryTreeNode(16);
  
  root->m_left = node6;
  root->m_right = node14;
  node6->m_left = node4;
  node6->m_right = node8;
  node14->m_left = node12;
  node14->m_right = node16;
  
  // std::cout<<"....print binary tree...\n";
  // inOrderTraverse (root);
  
  // build double linked list
  BinaryTreeNode* head = buildDoubleLinked(root);
  printLinkedlist(head); 
}