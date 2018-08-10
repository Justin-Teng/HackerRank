/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  Node* h = head;
  if (position == 0) {
      h = head->next;
      delete head;
      return h;
  }
  for (int i = 0; i < position-1; i++) {
      head = head->next;
  }
  Node* temp = head->next;
  head->next = temp->next;
  delete temp;
  return h;
}
