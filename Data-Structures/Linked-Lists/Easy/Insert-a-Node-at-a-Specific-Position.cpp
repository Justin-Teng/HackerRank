/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  Node *n = new Node();
  n->data = data;
  if (head == NULL) {
      head = n;
      n->next = NULL;
      return n;
  }
  Node *h = head;
  //cout << "Contents: " << head->data;
  for (int i = 0; i < position-1; i++) {
      head = head->next;
      //cout << head->data;
  }
    //cout << endl;
  
  if (position == 0) {
      n->next = head;
      return n;
  }
  else if (head->next == NULL) {
      head->next = n;
      n->next = NULL;
  }
  else {
      n->next = head->next;
      head->next = n;
  }
  return h;
}
