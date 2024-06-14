// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insert_node(Node*&head , int val){
    Node* new_node = new Node(val);
    
    if(head == NULL){
        head = new_node;
    }
    else{
        Node* temp_head = head;
        while(temp_head->next!=NULL){
            temp_head = temp_head->next;
        }
        temp_head->next = new_node;
    }
    return;
}
void delete_node(Node*&head,int val){
    Node* temp = head;
    Node* prev = NULL;
    
    if(temp!=NULL && temp->data == val){
        Node* to_del = temp;
        head = temp->next;
        delete to_del;
    }
    
    
    while(temp!=NULL && temp->data!=val){
        prev = temp;
        temp=temp->next;
    }
    
    if(temp==NULL) return;
    prev->next  = temp->next;
    delete temp;
    return;
}
void display(Node*&head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    return;
}


int main() {
    Node* head = NULL;
    insert_node(head,1);
    insert_node(head,2);
    insert_node(head,3);
    insert_node(head,4);
    display(head);
    delete_node(head,2);
    display(head);
    delete_node(head,4);
    display(head);

    return 0;
}
