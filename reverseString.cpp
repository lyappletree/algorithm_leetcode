#include <iostream>
#include <stddef.h>
#include <string>

struct ListNode
{
   std::string m_value;
   ListNode *m_next;
   ListNode(std::string value){this->m_value=value;this->m_next = NULL;};
};

void Reverse(char *pBegin, char *pEnd)
{
  if(pBegin == NULL || pEnd == NULL)
     return;
  while(pBegin < pEnd)
  {
    char temp = *pBegin;
	*pBegin = *pEnd;
	*pEnd = temp;
	pBegin++, pEnd--;
  }
}

char* ReverseSentence(char *pData)
{
  if(pData == NULL)
    return NULL;
	
  char *pBegin = pData;
  char *pEnd = pData;
  
  while(*pEnd!='\0')
    pEnd++;
  pEnd--;
  
  Reverse(pBegin, pEnd);
  
  pBegin = pEnd = pData;
  while(*pBegin!='\0')
  {
    if(*pBegin == ' ')
	{
	  pBegin++;
	  pEnd++;
	}
	else if(*pEnd == ' ' || *pEnd == '\0')
	{
	  Reverse(pBegin, --pEnd);
	  pBegin == ++pEnd;
	}
	else
	  pEnd++;
  }
  
  return pData;
}

ListNode* reverseList(ListNode* head)
{
  std::cout<<"head...."<< head->m_value <<"\n";
  ListNode* p = head;
  ListNode* q = p->m_next;
  ListNode* h = q->m_next;
  std::cout<<"h...."<< h->m_value <<"\n";
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

void printList(ListNode* head)
{
   while(head!=NULL)
     {
	    std::cout<< head->m_value<<" ";
		head = head->m_next;
	 }
   std::cout<<"\n";
}

ListNode* reverseString (std::string str)
{

  std::string new_str ="";
  ListNode* head;
  ListNode* result = new ListNode("");
  bool flag = false;
  std::cout<<"Ying LIu....1\n";
  int i=0;

  while ( str[i]!='\0')
  {  std::cout<<"Ying LIu....2\n";
    if (str[i]!=' ')
	 {
      new_str = new_str+ str[i];
	  std::cout<<"new_str.2.." << new_str <<"\n";
	  }
	else
	 {  std::cout<<"Ying LIu....3\n";
	 std::cout<<"new_str..." << new_str <<"\n";
	   ListNode* node = new ListNode(new_str);
	   result->m_next = node;
	   if (flag == false)
	      {  std::cout<<"Ying LIu....4\n";
		    head = node;
			flag = true;
		  }
	   std::cout<<"Ying LIu....5\n";
	   result = node;
	   std::cout<<"Ying LIu....6\n";
	   new_str = "";
	   std::cout<<"Ying LIu....7\n";
	 }
	
    i++;
  }
  std::cout<<"new_str.3.." << new_str <<"\n";
  ListNode* node = new ListNode(new_str);
  result->m_next = node;
  std::cout<<"Ying LIu....8\n";
  printList(head);
  head = reverseList(head);
  
  std::cout<<"Ying LIu....9\n";
  
  return head;
}


int main(int argc, char** argv) {

ListNode* head =  reverseString ("I am a student.");
printList(head);

}
