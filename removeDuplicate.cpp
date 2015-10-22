#include <vector>
#include <algorithm> 

struct LinkedList{
  int data;
  LinkedList* next;
  LinkedList (int x) {this->data = x; this->next=NULL;}
};

LinkedList* RemoveDuplicate( LinkedList* head)
{
  LinkedList *p = head->next;
  LinkedList *q = head;
  std::vector<int> visited;
  visited.push_back(q->data);
  while (p!=NULL)
  {
    // already visited
    if(std::find(visited.begin(), visited.end(), p->data)!=visited.end())
	  {
	    
	    q->next = p->next;
		p = q->next;
	  }
	else  // not visited
	  {
	    visited.push_back(p->data);
	    p = p->next;
		q = q->next;
	  }
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

int main(int argc, char** argv)
{
  LinkedList* head = new LinkedList(1);
  LinkedList* q;
  q = head;
  int dt[8] = {1, 4, 3, 4, 5, 5, 8, 2}; 
  for (int i=1; i<8; i++)
    {	   
	   LinkedList* hd = new LinkedList(dt[i]);
	   q->next = hd;
	   q = q->next; 
    }
  printLinkedList(head);
  //remove duplicate
  head = RemoveDuplicate(head);  
  printLinkedList(head);
}