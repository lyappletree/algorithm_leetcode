#include <stddef.h>
#include <iostream>
#include <string>
#include <map>

struct ListNode
{
  string m_value;
  ListNode* m_next;
  ListNode(string value){this->m_value = value; this->m_next = NULL;};
};

string findThebeginning(ListNode* head)
{
   ListNode* p = head;
   std::map<string, int> mymap;
   std::map<string, int>::iterator it; 
   
   while (p!=NULL)
  {
    it = mymap.find(p->m_value);
    if(it == mymap.end())
	  mymap[p->m_value] = 1;
	else
	  break;  
    p=p->m_next;
  }
  return p->m_value; 
}


int main()
{
  ListNode* node1 = new ListNode("1"); 
  ListNode* node2 = new ListNode("2");
  node1->m_next = node2; 
  ListNode* node3 = new ListNode("3");
  ListNode* node4 = new ListNode("4");
  ListNode* node5 = new ListNode("5");
  ListNode* node6 = new ListNode("6");
  node2->m_next = node3;
  node3->m_next = node4;
  node4->m_next = node5;
  node5->m_next = node6;
  node6->m_next = node3;
  
  string str = findThebeginning(node1);
  std::cout<<str;
  return 1;
}