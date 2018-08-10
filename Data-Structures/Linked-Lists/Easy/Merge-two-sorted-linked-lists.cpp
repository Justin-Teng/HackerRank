/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  Node* head;
  if (headB==nullptr && headA==nullptr) {
      return head;
  }
  if (headB==nullptr || (headA!=nullptr && headA->data < headB->data)) {
      head = headA;
      headA = headA->next;
  }
  else {
      head = headB;
      headB = headB->next;
  }
  Node* temp = head;
  while (headA!=nullptr || headB!=nullptr) {
      if (headB==nullptr || (headA!=nullptr && headA->data < headB->data)) {
          temp->next = headA;
          headA = headA->next;
          temp = temp->next;
      }
      else {
          temp->next = headB;
          headB = headB->next;
          temp = temp->next;
      }
  }
  temp->next = nullptr;
  return head;
}
