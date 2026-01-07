#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};


void traverse(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtBeginning(Node* &head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd (Node* &head, int value){
    Node* newNode = new Node(value);


    Node* temp = head;

    while (temp->next!= NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}





int main()
{
 

    Node* head = NULL;

    insertAtBeginning(head, 10);
    insertAtEnd(head, 30);
    insertAtEnd(head, 50);
    traverse(head);
    return 0;
}