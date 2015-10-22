#include <stddef.h>
#include <iostream>

struct ListNode
{
  int m_value;
  ListNode* m_next;
  ListNode(int value){this->m_value = value; this->m_next = NULL;};
};

int main()
{
   ListNode* node1 = new ListNode(1);
   ListNode* node2 = new ListNode(2);
   ListNode* node3 = new ListNode(3);
   ListNode* node4 = new ListNode(4);
   ListNode* node5 = new ListNode(5);
   ListNode* node6 = new ListNode(6);
   
   node1->m_next = node2;
   node2->m_next = node3;
   node3->m_next = node4;
   node4->m_next = node5;
   node5->m_next = node6;
   
   ListNode* p = node1;
   ListNode* q = node1;
   
   int i =0;
   
   while(p!=NULL)
   {
     
	 if(i>2)
	   {
	     q= q->m_next;
	   }
	 p = p->m_next;
	 i++;
   }
   
   std::cout<<q->m_value;
   
   return 1;
}