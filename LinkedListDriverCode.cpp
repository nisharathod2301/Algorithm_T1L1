#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Making a linked list
class node{
    public:
    int data;       
    node* next;     
    node (int val){
        data = val;
        next = NULL;
    }
};

void insertt(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void displayn(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
    }
}

int main() {
    // std::cout << "Hello world!";
    node* head = NULL;
    insertt(head,1);

    // displayn(head);
    return 0;
}
