#include <iostream>
#include <stddef.h>
#include <map>

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

ListNode* findkthNode(ListNode* head, int k)
{
   ListNode* p = head;
   ListNode* q = head;
   int i=0;
   while(q!=NULL)
   {
     for(; i<k; i++)
	   q = q->m_next;
	 if ( i>= k)
	   {
	     p = p->m_next;
		 q = q->m_next;
	   }
   }
   return p;
}

ListNode* reverseList(ListNode* head)
{
  ListNode* p = head;
  ListNode* q = p->m_next;
  ListNode* h = q->m_next;
  p->m_next = NULL;
  while (h!=NULL)
  {
    std::cout<<"p........." << p->m_value <<" ";
    q->m_next = p;
	p = q;
	q = h;
	h = h->m_next;
  }
  q->m_next = p;
  return q;
}

ListNode* findTail(ListNode* head)
{
  ListNode* p = head;
  while(p->m_next!=NULL)
    p = p->m_next;
  return p;
}

bool hasAloop(ListNode* head)
{
  ListNode* p = head;
  ListNode* q = head; 
  
  while(p!=NULL && q!=NULL)
    {
	   p = p->m_next;
	   q = q->m_next;
	   q = q->m_next;
	   if(p == q)
	      return true;
	}
  return false;
}

ListNode* findEntryLoop(ListNode* head)
{
   ListNode *p = head;
   bool flag = false;
   std::map<int, int> mymap;
   std::map<int, int>::iterator it;
   
   while(p!=NULL)
   {
     it = mymap.find(p->m_value);
	 if (it == mymap.end())
        mymap.insert(std::pair<int, int>(p->m_value, 1)); 
	 else
	    break;
     p = p->m_next;
   }
   return p;
}

ListNode* MeetingNode(ListNode* pHead)
{
   if(pHead == NULL)
      return NULL;
 
   ListNode* pSlow = pHead->m_next;
   if(pSlow == NULL)
     return NULL;
   
   ListNode* pFast = pSlow->m_next;
   while(pFast!=NULL && pSlow!=NULL)
     {
	   if(pFast == pSlow)
	      return pFast;
	   pSlow = pSlow->m_next;
	   
	   pFast = pFast->m_next;
	   if(pFast!=NULL)
	      pFast = pFast->m_next;
	 }
   return NULL;
}

ListNode *EntryNodeOfLoop(ListNode* pHead)
{
  ListNode* meetingNode = MeetingNode(pHead);
  if(meetingNode == NULL)
    return NULL;
	
  int nodesInLoop = 1;
  ListNode* pNode1 = meetingNode;
  while(pNode1->m_next= meetingNode)
  {
    pNode1 = pNode1->m_next;
	nodeInLoop++;
  }
  
  pNode1 = pHead;
  for(int i=0; i<nodesInLoop; ++i)
    pNode1 = pNode1->m_next;
  
  ListNode* pNode2 = pHead;
  while(pNode1!= pNode2)
    {
	  pNode1 = pNode1->m_next;
	  pNode2 = pNode2->m_next;
	}
  return pNode1;
}

int main(int argc, char** argv) {
    int a[6] = {1, 2, 3, 4, 5, 6};
    ListNode* head = Buildlist(a, 6);
    printList(head);
	ListNode* km = findkthNode(head, 5);
	std::cout<<"km...." << km->m_value <<"\n";
	
	// ListNode* tail = reverseList(head);
	// printList(tail);
	ListNode* tail = findTail(head);
	std::cout<<"tail...."<< tail->m_value<<"\n";
	tail->m_next = km;
	
	// find a loop
	bool has = hasAloop(head);
	std::cout<<"has...." << has <<"\n";
	
	ListNode* entry = findEntryLoop(head);
	std::cout<<"entry...." << entry->m_value<<"\n";
}