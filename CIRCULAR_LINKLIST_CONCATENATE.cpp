#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node*next;
    node*prev;
};
////////////INSERTING AT END/////////////
void insert_at_end(node* &head,int value)
{
    node*h=head;
    node* new_node=new node;
    new_node->data=value;
    node*temp=head;
    if(head==NULL)
    {
        head=new_node;
        new_node->next=head;
        //HERE NODE IS POINTING TO ITSLEF
    }
    else
    {
        while(temp->next!=h)
        {
            temp=temp->next;
        }
        node*temp2=temp->next;
        temp->next=new_node;
        new_node->next=head;
    }
}
///////////CONCATENATE TWO LINK LIST USING CIRCULAR LINK LIST////////////
void concatenate_lists(node* &head1,node* &head2)
{
    node* temp1=head1;
    node* h1=head1;
    node* temp2=head2;
    node*h2=head2;
    while(temp1->next!=h1)
    {
        temp1=temp1->next;
    }
    temp1->next=h2;
    while(temp2->next!=h2)
    {
        temp2=temp2->next;
    }
    temp2->next=h1;
}
///////////DISPLAYES LINK LIST///////////////
void display(node*  head)
{
    node*temp=head;
    do
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    } while(temp!=head);
    cout<<head->data<<endl;
}
/////////////INT MAIN//////////////////
int main()
{
    node*head1=NULL;
    node*head2=NULL;
    cout<<"Elements of 1st list:"<<endl;
    for(int i=1;i<=10;i++)
    {
        insert_at_end(head1,i);
    }
    display(head1);
    cout<<"Elements of 2nd list:"<<endl;
     for(int i=11;i<=20;i++)
    {
        insert_at_end(head2,i);
    }
    display(head2);
    cout<<"Concatenated lists"<<endl;
    concatenate_lists(head1,head2);
    display(head1);

}
