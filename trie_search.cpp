#include <iostream>
#include <string>
#include <stddef.h>
using namespace std;

#define ALPHABET_SIZE 3


struct trieNode
{
  char value;
  trieNode *children[ALPHABET_SIZE];
  int number_children;
  trieNode (char s){
    this->value = s; 
	for (int i=0; i< ALPHABET_SIZE; i++)
	   this->children[i] = NULL;
	this->number_children = 0;
	};
};

void print(trieNode* root, int length)
{
std::cout<<"Ying Liu...13....\n";
  std::cout<< root->value <<" ";
  std::cout<<"Ying Liu...14....\n";
  trieNode* current = root->children[0];
  std::cout<<"Ying Liu...15....\n";
  std::cout<< current->value<<" ";   // a
  std::cout<<"Ying Liu...16....\n";
  current = current->children[0];
  std::cout<<"Ying Liu...17....\n";
  std::cout<< current->value<<" ";    // b
  std::cout<< current->children[0]->value<<" ";
  std::cout<< current->children[1]->value<<" ";
  
}

trieNode* buildTrie (string str_array[], int number)
{
  trieNode* root = new trieNode('\0');
  for (int i=0; i< number; i++)
   {  std::cout<<"Ying Liu.......\n";
     trieNode* current = root;
	 string currentStr = str_array[i];
     int len = str_array[i].length();
	 for (int j= 0; j< len; j++)
	   {  std::cout<<"Ying Liu...2....\n";
	      bool flag = false;
		  int m = 0;
		  if (current->number_children == 0)
		    {
			   trieNode* node = new trieNode(currentStr[j]);
			   current->children[0] = node;
			   current->number_children++;	
			   current = current->children[0];
               			   
			}
		  else {
	      for (; m< ALPHABET_SIZE; m++)
		    {  std::cout<<"Ying Liu....3...\n";
			   trieNode* currentSub = current->children[m];
			   std::cout<<"Ying Liu....5.. " << currentStr[j] <<"\n";
			   char ss = currentStr[j];
			   std::cout<<"Ying Liu....7...\n";
			   if (currentSub!=NULL)
			   {
			      char ss2 = currentSub->value;
			   std::cout<<"Ying Liu....8...\n";
			   if(ss2 == ss)
			    {  std::cout<<"Ying Liu....4...\n";
				  flag = true;
			      break;
				}
				}
			}
		  std::cout<<"Ying Liu...6....\n";
		  if ( flag == false)
		     {  std::cout<<"Ying Liu...8....\n";
			   trieNode* node = new trieNode(currentStr[j]);
			   current->children[m] = node;
			   current->number_children++;
			   current = current->children[m];
			   std::cout<<"Ying Liu...9....\n";
			 }	
          }			 
	   }
	   std::cout<<"Ying Liu...10....\n";
	   // current = current->children[0];
	   std::cout<<"Ying Liu...11....\n";
   }
  print(root, 3);   
   return root;
}


int main()
{
  string str_array[3] = {"abc", "abd", "mnk"};
  
  trieNode* root = buildTrie (str_array, 3);
  std::cout<<"Ying Liu...12....\n";
  // print(root, 3);
  return 1;
}