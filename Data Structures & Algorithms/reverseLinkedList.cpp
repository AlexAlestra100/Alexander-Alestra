#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

void reverseList(Node* head)
{
   Node* curr = head;
   Node* next = NULL;
   Node* prev = NULL;

   while(curr != NULL)
   {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
   }
   head = prev;
}

void printList(Node* n)
{
   while (n != NULL) {
      cout << n->data << endl;;
      n = n->next;
   }
}

int main() 
{
   Node* head = NULL;
   Node* second = NULL;
   Node* third = NULL;

   head = new Node();
   head->data = 1;

   second = new Node();
   second->data = 2;

   third = new Node();
   third->data = 3;

   head->next = second;
   second->next = third;
   third->next = NULL;

   reverseList(head);

   printList(third);

   return 0;
}