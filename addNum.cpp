#include <iostream>
#include <stddef.h>

struct ListNode
{
   int m_value;
   int m_visited;
   ListNode *m_next;
   ListNode(int value){this->m_value=value; this->m_visited = 0; this->m_next = NULL;};
};

ListNode* Buildlist(int a[], int length)
{
  ListNode* p = new ListNode(a[0]);
  ListNode* head;
  head = p;
  for (int i=1; i<length; i++)
     {
	    ListNode* node = new ListNode(a[i]);
		p->m_next = node;
		p = p->m_next;
	 }
  return head;   
}

void printList(ListNode* head)
{
   while(head!=NULL)
     {
	    std::cout<< head->m_value<<" ";
		head = head->m_next;
	 }
   std::cout<<"\n";
}

ListNode* reverseList(ListNode* head)
{
  ListNode* p = head;
  ListNode* q = p->m_next;
  ListNode* h = q->m_next;
  p->m_next = NULL;
  while (h!=NULL)
  {
    q->m_next = p;
	p = q;
	q = h;
	h = h->m_next;
  }
  q->m_next = p;
  return q;
}

ListNode* addTwoNum(ListNode* head1, ListNode* head2)
{
    int carry = 0;
	ListNode* p = reverseList(head1);
	ListNode* q = reverseList(head2);
	ListNode* result = new ListNode(p->m_value + q->m_value);
	ListNode* head;
	bool first = false;
	while(p!=NULL && q!=NULL)
	{
	
	   int sum = p->m_value + q->m_value + carry;
	   std::cout<<"sum....." << sum <<"\n";
	   if (sum >=10)
	     {
	        carry = 1;
			sum = sum - 10;
		 }
		else
		   carry = 0;	
       ListNode* node = new ListNode(sum);
	   if(first== false)
	    {
	       head = node;
		   first = true;
		}
       result->m_next = node;	  
       result = result->m_next;	   
	   p = p->m_next;
	   q = q->m_next;
	}
	printList(head);
	
	if ( p== NULL && q== NULL)
	  {
	   if(carry != 0)
	     {
		   ListNode* node = new ListNode(carry);
		   result->m_next = node;
		 }
	  }
    if (p!=NULL && q == NULL)
	 {
	 
	   while(p!=NULL)
	   {
	     p->m_value = p->m_value+ carry;
		 result->m_next = p;
		 p = p->m_next;
		 result = result->m_next;
	     carry = 0;
	   }	   
	 }
	 
	 if (p==NULL && q != NULL)
	 {
	   std::cout<<"Ying LIu\n";
	   while(q!=NULL)
	   {
	     q->m_value = q->m_value+ carry;
		 result->m_next = q;
		 q = q->m_next;
		 result = result->m_next;
	     carry = 0;
	   }	   
	 }
	 
	 head = reverseList(head);
     return head;
}


int main(int argc, char** argv) {
    int a[4] = {7, 1, 2, 3};
    ListNode* head1 = Buildlist(a, 4);
    printList(head1);
	
    int b[4] = {4, 5, 6, 7};
    ListNode* head2 = Buildlist(b, 4);
    printList(head2);
	
	ListNode* result = addTwoNum(head1, head2);
	printList(result);
	
}