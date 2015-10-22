#include <math.h> 
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

// recursive way
BinaryTreeNode *insertAnode(int value, BinaryTreeNode* node)
{
  if (node == NULL)
    {
	  BinaryTreeNode *node2 = new BinaryTreeNode(value);
	  return node2;
	}
  else if(value < node->m_value)
    {
      BinaryTreeNode *left = insertAnode(value, node->m_left);
	  node->m_left = left;
	}
  else
    {
      BinaryTreeNode *right = insertAnode(value, node->m_right);
	  node->m_right = right;
	}
}

BinaryTreeNode *BuildATree(int a[], int length, int root_v)
{
     // int mid = (int)floor(length/2);
     BinaryTreeNode *head = new BinaryTreeNode(root_v);
	 // BinaryTreeNode *root = head;
	 for (int i=0; i<length; i++)
	   if (a[i]!= root_v)
         insertAnode(a[i], head);
	  
	  return head;	 
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
  if(pNode == NULL)
     return;
  BinaryTreeNode *pCurrent = pNode;
  
  if(pCurrent->m_left!=NULL)
     ConvertNode(pCurrent->m_left, pLastNodeInList);
	 
   pCurrent->m_left = *pLastNodeInList;
   if(*pLastNodeInList!=NULL)
      (*pLastNodeInList)->m_right = pCurrent;
   
   *pLastNodeInList = pCurrent;
   
   if(pCurrent->m_right!=NULL)
     ConvertNode(pCurrent->m_right, pLastNodeInList);
}

// in order 
void printTree (BinaryTreeNode* tree)
{
  if (tree == NULL)
     return;
  printTree(tree->m_left);
  std::cout<< tree->m_value <<" ";
  printTree(tree->m_right);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
  BinaryTreeNode *pLastNodeInList = NULL;
  ConvertNode(pRootOfTree, &pLastNodeInList);
  
  // pLastNodeInList points to the tail of double-linked list,
  // but we need to return its head
  BinaryTreeNode *pHeadOfList = pLastNodeInList;
  while(pHeadOfList!= NULL && pHeadOfList->m_left!=NULL)
   {
     std::cout<<pHeadOfList->m_value<< " ";
     pHeadOfList = pHeadOfList->m_left;
   } 
  return pHeadOfList;
}

/* void FindPath (BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum)
{
  currentSum+= pRoot->m_value;
  path.push_back(pRoot->m_value);
  
  //Print the path is the current node is a leaf
  //and the sum of all nodes value is same as expectedSum
  bool isLeaf= pRoot->m_left == NULL && pRoot->m_right == NULL;
  if (currentSum == expectedSum && isLeaf)
  {
     std::cout<<"A path is found:\n";
	 std::vector<int>::iterator iter = path.begin();
	 for(; iter!= path.end(); ++iter)
	    std::cout<<*iter<<" ";
	 std::cout<<"\n";
  }
  
  if(pRoot->m_left!=NULL)
    FindPath(pRoot->m_left, expectedSum, path, currentSum);
  if(pRoot->m_right!=NULL)
    FindPath(pRoot->m_right, expectedSum, path, currentSum);
 
  path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
   if(pRoot == NULL)
      return;
   std::vector<int> path;
   int currentSum = 0;
   FindPath(pRoot, expectedSum, path, currentSum);
}*/

bool VerifySquenceOfBST(int sequence[], int length)
{
  if(sequence == NULL || length<=0)
     return false;
  
  int root = sequence[length-1];
  
  //nodes in left sub-tree are less than root node
  int i=0;
  for(; i< length-1; ++i)
  {
    if(sequence[i]> root)
	  break;
  }
	
  //nodes in right sub-tree are greater than root node
  int j=i;
  for (; j<length-1; ++j)
  {
    if(sequence[j] < root)
	  return false;
  }
  
  // Is left sub-tree a binary search tree?
  bool left = true;
  if(i>0)
    left = VerifySquenceOfBST(sequence, i);

  // Is right sub-tree a binary search tree?
  bool right = true;
  std::cout<<"i...."<<i<<"\n";
  if(i< length-1)
    right = VerifySquenceOfBST(sequence+i, length-i-1);
	
  return(left&&right);
}

struct Distance
{
   int m_dis;
   BinaryTreeNode *node;  
   Distance(int dis){this->m_dis = dis; this->node = NULL;};
};

Distance* findclosestNode(BinaryTreeNode* tree, int target)
{
   std::cout<<"Ying LIu....1"<< target <<" "<< tree->m_value <<"\n";
   Distance* dis = new Distance(100);
   while (dis->m_dis > std::abs(tree->m_value - target))
      {
	    dis->m_dis = std::abs(tree->m_value - target);		
		dis->node = tree;
		
	    std::cout<<"distance...." << dis->m_dis <<"\n";
		std::cout<<"node...." << ((dis->node)->m_value)<<"\n";
		
        if(target<tree->m_value)
		 {
          tree= tree->m_left;
		  std::cout<<"left...." << tree->m_value <<"\n";
		  std::cout<<"right...." << tree->m_right->m_value <<"\n";
		 }
        else
          tree = tree->m_right;
	  }
   return dis;
      
}

BinaryTreeNode* getClosestNode(BinaryTreeNode* pRoot, int value)
{
  BinaryTreeNode* pClosest = NULL;
  int minDistance = 0x7FFFFFFF;
  BinaryTreeNode* pNode = pRoot;
  while(pNode!= NULL)
  {
    int distance = abs(pNode->m_value - value);
	if(distance< minDistance)
	  {
	     minDistance = distance;
		 pClosest = pNode; 
	  }
	
	if(distance == 0)
	  break;
	if(pNode->m_value > value)
	   pNode = pNode->m_left;
	else if(pNode->m_value < value)
	   pNode = pNode->m_right;
  }
  return pClosest; 
}

void buildNextNodes(BinaryTreeNode* pRoot, stack<BinaryTreeNode*>& nodes)
{
  BinaryTreeNode* pNode = pRoot;
  while(pNode!= NULL)
  {
    nodes.push(pNode);
	pNode = pNode->m_left;
  }
}

void buildPrevNodes(BinaryTreeNode* pRoot, stack<BinaryTreeNode*>& nodes)
{
  BinaryTreeNode* pNode = pRoot;
  while(pNode!= NULL)
  {
    nodes.push(pNode);
	pNode = pNode->m_right;
  }
}

BinaryTreeNode* getNext(stack<BinaryTreeNode*>& nodes)
{
  BinaryTreeNode* pNext = NULL;
  if(!nodes.empty())
  {
    pNext = nodes.top();
	nodes.pop();
	
	BinaryTreeNode* pRight = pNext->m_right;
	while(pRight!=NULL)
	{
	   nodes.push(pRight);
	   pRight = pRight->m_left;
	}
  }
  
  return pNext;
}

BinaryTreeNode* getPrev(stack<BinaryTreeNode*>& nodes)
{
  BinaryTreeNode* pPrev = NULL;
  if(!nodes.empty())
  {
    pPrev = nodes.top();
	nodes.pop();
	
	BinaryTreeNode* pLeft = pPrev->m_left;
	while(pLeft!= NULL)
	{
	  nodes.push(pLeft);
	  pLeft = pLeft->m_right;
	}
  }
  
  return pPrev;
}

bool hasTwoNodes(BinaryTreeNode* pRoot, int sum, int& value1, int& value2)
{
  stack<BinaryTreeNode*> nextNodes, prevNodes;
  buildNextNodes(pRoot, nextNodes);
  buildPrevNodes(pRoot, prevNodes);
  
  BinaryTreeNode* pNext = getNext(nextNodes);
  BinaryTreeNode* pPrev = getPrev(prevNodes);
  
  while(pNext!=NULL && pPrev!= NULL && pNext!= pPrev)
   {
     int currentSum = pNext->m_value + pPrev->m_value;
	 std::cout<<"Ying Liu..."<< pNext->m_value <<" "<< pPrev->m_value <<"\n";
	 // value1 = &(pNext->m_value);
	 // value2 = &(pPrev->m_value);
	 value1 = pNext->m_value;
	 value2 = pPrev->m_value;
	 
	 if(currentSum == sum)
	    return pRoot;
	 if(currentSum < sum)
	    pNext = getNext(nextNodes);
     else
	    pPrev = getPrev(prevNodes);
   }
   
   return false;
}

bool findSum(int a[], int length, int sum, int& value1, int& value2)
{
   int i =0;
   int j = (length-1);
   int current_sum = 0;
   while(i!=j)
   {
     current_sum = a[i]+a[j];
	 value1 = a[i];
	 value2 = a[j];
	 if(current_sum < sum)
        i=i+1;
     if(current_sum == sum)
	    return true;
     if(current_sum > sum)
	    j = j-1;
   }
   return false;
}


int main(int argc, char** argv) {
   // int a[7] = {4, 6, 8, 10, 12, 14, 16}; 
   int a[11] = {14, 21, 24, 25, 28, 31, 32, 36, 39, 41, 47};
   // build a binary search tree
   BinaryTreeNode* tree;
   tree = BuildATree(a,11, 32);
   // printTree(tree);
   
   // Distance* d=findclosestNode(tree, 29);
   // std::cout<<"distance....."<< d->node->m_value <<"\n";
   BinaryTreeNode* node = getClosestNode(tree, 29);
   std::cout<<"node......" << node->m_value <<"\n";
   
   int value1=0;
   int value2=0 ;
   // bool flag = hasTwoNodes(tree, 35, value1, value2);
   bool flag = findSum( a, 11, 66, value1, value2);
   std::cout<<"sum....."<< value1 <<" "<< value2 <<"\n";
   
   // Build double link
   // BinaryTreeNode *head = Convert(tree);
   int b[7] = {5, 7, 9, 6, 11, 10, 8};
   bool m = VerifySquenceOfBST(b, 7);
   std::cout<<"m...." << m;
   return 1;
}









