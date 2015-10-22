struct Queue
{
    int val;
    List* next;
    List(int value){this->val=value; next=NULL;};
};

void push(int x, Queue &q1, Queue &q2)
{
   Queue* head = q1;
   
   while(head!=NULL)
     head = head->next;
	 
   Queue* tmp = new tmp(x);
   
   head = tmp;
}

int top(Queue &q1, Queue &q2)
{
}

int main()
{
  int a[6] = {1,2,3,4,5,6};
  Queue *head1;
  Queue *head2;
  return 1;
}