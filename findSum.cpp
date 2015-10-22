//Input/output stream
#include<iostream>
#include<vector>
#include<memory>

struct BinaryTreeNode
{
   int m_value;
   BinaryTreeNode* m_pLeft;
   BinaryTreeNode* m_pRight;
   BinaryTreeNode(int value){this->m_value = value; this->m_pLeft = NULL; this->m_pRight = NULL; }
};

class BuildBinaryTree{

  private: void addNode(BinaryTreeNode* root, int value);
  public: BinaryTreeNode* buildBinaryTree (int num[], int length);
          void printBinaryTree(BinaryTreeNode* root);

};

BinaryTreeNode* 
BuildBinaryTree::buildBinaryTree (int num[], int length)
{
   BinaryTreeNode* root = new BinaryTreeNode(num[0]);
   BinaryTreeNode* head = root;
   for (int i =1; i<length; i++) 
   {
     addNode(root, num[i]);
	 std::cout<< "poiner ....." << root->m_pRight << " " << root->m_pLeft<<"\n";
	 std::cout<<"Ying Liu .... 2"<< num[i] <<"\n";
   }
   // std::cout<< "poiner ....." << head->m_pRight << " " << head->m_pLeft<<"\n";
   return head; 
}

void
BuildBinaryTree::addNode(BinaryTreeNode* root, int value)
{
   if (root == NULL) {
   std::cout<<"Ying Liu .... 3"<<"\n";
        root = new BinaryTreeNode (value);
   }
   else if (root->m_value < value)
    {
	  std::cout<<"Ying Liu .... 4"<<"\n";
      addNode(root->m_pRight, value);
	}
   else
    {
	  std::cout<<"Ying Liu .... 5"<<"\n";
      addNode(root->m_pLeft, value);
	}
}

void 
BuildBinaryTree::printBinaryTree(BinaryTreeNode* root)
{
  if(root==NULL)
     return;
  else
   {
     printBinaryTree(root->m_pLeft);
	 std::cout<<root->m_value<<" ";
	 printBinaryTree(root->m_pRight);
   }
}


int main(int argc, char** argv)
{
  int num[] = {47,24,41,14,25,31,39,21,28,36,32}; 
  int length = sizeof(num)/sizeof(*num);
  BuildBinaryTree* tree;
  BinaryTreeNode* root = tree->buildBinaryTree (num, length);
  tree->printBinaryTree(root);
  
  BinaryTreeNode* root1 = new BinaryTreeNode(1);
  BinaryTreeNode* root2 = new BinaryTreeNode(2);
  BinaryTreeNode* root3 = new BinaryTreeNode(3);
  root1->m_pLeft = root2;
  root1->m_pRight = root3;
  tree->printBinaryTree(root1);
  return -1;
}

















