#include <iostream>

using namespace std;
/////////////CREATE NODE///////////////
class node
{
public:
    int data;
    node* next;
    node* prev;
};
////////////INSERT AT HEAD//////////////
void insert_at_head(node* &head,int value)
{
    node* new_node=new node;
    new_node->data=value;
    new_node->next=head;
    if(head!=NULL)
        {
        head->prev=new_node;
        }
        new_node->prev=NULL;
        head=new_node;
}
////////INSERT AT END//////////////////
void insert_at_tail(node* &head,int value)
{
    node* new_node=new node;
    new_node->data=value;
    new_node->next=NULL;
   new_node->prev=NULL;
    if(head==NULL)
    {
        head=new_node;
        head->prev=NULL;
        head->next=NULL;
    }
    else{
        node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
    }

}
////////////DELETE NODE//////////////////
void delete_node(node* &head,int value)
{
    node* temp=head;
    while(temp->next->data!=value)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->next->prev=temp->next;
}
/////////////DELETES FIRST NODE//////////////
void delete_the_first(node* &head)
{
    node*temp=head;
    head=head->next;
    head->next->prev=NULL;
    delete temp;
}
////////////DELETES LAST NODE////////////
void delete_the_last(node* &head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* discard=temp->next;
    temp->next=NULL;
    delete discard;
}
///////////DISPLAYS LINK LIST//////////////
void display(node* &head)
{
    node*temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
///////////INT MAIN////////////////////////
int main()
{
    node* head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_head(head,7);
    display(head);
    delete_node(head,4);
    display(head);
    delete_the_first(head);
    display(head);
    delete_the_last(head);
    display(head);
    return 0;
}
