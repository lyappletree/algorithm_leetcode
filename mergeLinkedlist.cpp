#include <stddef.h>
#include <iostream>

struct LinkedList{
  int data;
  LinkedList* next;
  LinkedList (int x) {this->data = x; this->next=NULL;}
};

LinkedList* buildLinkedList(int a[], int length)
{
  LinkedList* head = new LinkedList(a[0]);
  LinkedList* q;
  q = head;
  
    for (int i=1; i<length; i++)
    {	
	   LinkedList* hd = new LinkedList(a[i]);
	   q->next = hd;
	   q = q->next; 
    }
  return head; 
}

void printLinkedList(LinkedList* head)
{  
  LinkedList* p = head;
  while(p!=NULL)
  {
    std::cout<<p->data<<" ";
    p=p->next;
  }
  std::cout<<"\n";
}

LinkedList* Merge (LinkedList* p, LinkedList* q)
{
   std::cout<<"Ying Liu.....2...\n";
   LinkedList* head;
   LinkedList* prev;
   // head = prev;
   prev = head;
   while(p!=NULL && q!=NULL)
   {
      LinkedList *tmp;
      if (p->data<= q->data)
	    {
	     tmp = new LinkedList(p->data);
		 p = p->next;
		}
	  else
	    {
	     tmp = new LinkedList(q->data);
		 q = q->next;
		}
      prev->next = tmp;
	  prev = prev->next;
	  
   }
   head = head->next;
   if(p==NULL && q ==NULL)
     return head;
   if(p==NULL)
     prev->next = q;
   else
   {
     prev->next = p;
	 std::cout<<"Ying Liu.....3...\n";
   }
   std::cout<<"Ying Liu.....1..."<< head->data <<"\n";
    std::cout<<"Ying Liu.....5..."<< head->next->data <<"\n";
   
   return head;
}

int main(int argc, char** argv)
{
  int a1[3] = {3, 2, 4}; 
  int a2[2] = {0, 8}; 
  LinkedList* p = buildLinkedList(a1, 3);
  printLinkedList(p);
  LinkedList* q = buildLinkedList(a2, 2);
  printLinkedList(q);
  LinkedList* head = Merge(p,q); 
  printLinkedList(head);
  
}