#include <iostream>
using namespace std;
////////////DOUBLE LINK LIST USED////////
class node
{
public:
    int data;
    node* next;
    node* prev;
};
////////////INSERTION AT HEAD//////////
void insert_at_head(node* &head,int value)
{
    node* new_node=new node;
    new_node->data=value;
    new_node->next=head;
    if(head!= NULL)
        {
        head->prev=new_node;
        }
        new_node->prev=NULL;
        head=new_node;
}
///////////////////INSERTION AT END///////
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
//////////////DELETE NODE//////////////
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
////////////////DELETE FIRST NODE //////////
void delete_the_first(node* &head)
{
    node*temp=head;
    head=head->next;
    head->next->prev=NULL;
    delete temp;
}
/////////////////DELETES LAST NODE////////////
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
///////////////SWAPS//////////////////////
void swap(node * &a, node* &b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
///////////////BUBBLE SORT/////////////
void bubble_sort(node* &head)
{

    int swapped,i=1;
    node* temp1;
    node*temp2=NULL;
    if (head == NULL)
        return;

    else
{
        do
        {
        swapped=0;
        temp1=head;
        while(temp1->next!=temp2)
        { cout<<"swap count :"<<i<<endl;
           i++;
              if (temp1->data > temp1->next->data)
            {
                swap(temp1, temp1->next);
                swapped = 1;
            }
            temp1=temp1->next;
        }
        temp2=temp1;
    }while(swapped);
}
}

//////////DISPLAYS////////////
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
//////////INT MAIN//////////
int main ()
{
    node* head=NULL;
    node*head1=NULL;
    node*head2=NULL;

    insert_at_head(head,7);
    insert_at_head(head,6);
    insert_at_head(head,9);
    insert_at_head(head,10);
    insert_at_head(head,3);
    insert_at_head(head,1);
    display(head);
    bubble_sort(head);
    display(head);


    return 0;
}
