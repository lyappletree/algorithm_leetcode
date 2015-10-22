#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  
  ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
          return NULL;
        std::cout<<"Ying Liu......6....\n";  
        if(head->next == NULL)
          return NULL;
        std::cout<<"Ying Liu......5....\n";
        if(head->next == head)
        {  std::cout<<"Ying Liu......7....\n";
          return head;
        }
        std::cout<<"Ying Liu......4....\n";  
        ListNode* p = head;
        ListNode* q = head->next;
        int countp = 0;
        int countq = 0;
        
        while(p!=q && p!=NULL && q!=NULL)
        {
            if(p!=NULL)
             {   
                 countp++;
                 p = p->next;
                 std::cout<<"Ying Liu......1....\n";
             }
            else
               return NULL;
               
            if(q!=NULL)
             {
                 countq++;
                 q = q->next;
                 std::cout<<"Ying Liu......2....\n";
             }
            else
               return NULL;
            
            if(q!=NULL)
            {
                countq++;
                q = q->next;
                std::cout<<"Ying Liu......3....\n";
            }
            else
               return NULL;
        }
        
        std::cout<< countp <<"...." << countq <<"\n";
        
        int length = 0;
        if(q==NULL || p==NULL)
          return NULL;
        else
           length = countq - countp; 
           
        p = head;
        q = head;
        for(int i=0; i<length;i++)
        { 
          q = q->next;
        }
        
        std::cout<<"p->val...."<< p->val <<"...."<<q->val<<"\n";
        while(q->next!=p)
        {
            // std::cout<<"Ying Liu......21....\n";
            q = q->next;
            p = p->next;
        }
        
        return p; 
        
    }
	
int main()
{
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  ListNode* node6 = new ListNode(6);
  ListNode* node3 = new ListNode(3);
  ListNode* node4 = new ListNode(4);
  ListNode* node5 = new ListNode(5);
  
  node1->next = node2;
  node2->next = node6;
  node6->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  
  ListNode* node = detectCycle(node1);
  
  std::cout<< node->val; 
  
  return -1;
}
 
 