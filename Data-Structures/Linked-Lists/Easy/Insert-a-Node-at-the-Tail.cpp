/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  if (head==nullptr) {
      Node *n = new Node();
      n->data = data;
      return n;
  }
  Node* h = head;
  while (head->next!=nullptr) {
      head = head->next;
  }
  Node* n = new Node();
  n->data = data;
  head->next = n;
  return h;
}
