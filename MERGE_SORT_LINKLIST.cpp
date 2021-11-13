#include <iostream>
using namespace std;
/////////////NODE STRUCUTRE///////////
class node
{
public:
    int data;
    node* next;
    node* prev;
};
/////////////DOUBLE LINK LIST USED////////////
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
void delete_the_first(node* &head)
{
    node*temp=head;
    head=head->next;
    head->next->prev=NULL;
    delete temp;
}
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
//////////////DOUBLE LINK LIST FUNTIONS DONE////////////////
<---------------------------------------------------------------------------------------------->
/////////////////////MERGE SORT IN LINK LIST/////////////////
void find_middle(node* &temp ,node* &first,node* &second)
{
    cout<<endl<<"finding the middle"<<endl;
    node* fast;
    node* slow;
    slow=temp;
    fast=temp->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
             fast=fast->next;
               slow=slow->next;

        }
      }
      first=temp;
      second =slow->next;
      slow->next=NULL;
      cout<<endl<<"Middle of link list is :"<<slow->data<<endl;
      node*f1=first;
      node*s2=second;

      cout<<endl<<"first array"<<endl;
      while(f1!=NULL)
      {
          cout<<f1->data<<"-";
          f1=f1->next;
      }
      cout<<endl<<"second : "<<endl;
      while(s2!=NULL)
      {
          cout<<s2->data<<"--";
          s2=s2->next;
      }
      cout<<endl;

}
///////////////MERGING LINK LIST/////////////////////////
node* merge_both(node* &first ,node* &second)
{
    node* ans=NULL;
    if(!first)
    {
        cout<<endl<<"what is happening returning second??  :"<<second->data<<endl;
        return second;
    }
    else if(!second)
    {
        cout<<endl<<"what is happening returning first??  :"<<first->data<<endl;
        return first;
    }
    if(first->data<=second->data)
    {
        ans=first;
        cout<<endl<<" if"<<first->data<<"<"<<second->data<<endl;
        ans->next=merge_both(first->next,second);
        cout<<endl<<"When first ka data is chotu run scucessfully"<<endl;
    }
    else
    {
        ans=second;
        cout<<endl<<" if"<<second->data<<"<"<<first->data<<endl;
        ans->next=merge_both(first,second->next);
        cout<<endl<<"When second  ka data is chotu run scucessfully"<<endl;
    }
    cout<<endl<<"Ans pointer points to this data: "<<ans->data<<endl;
    return ans;
}
//////////////////MERGE SORT FUNTION//////////////////
void merge_sort(node* &head)
{
    node * temp=head;
    node* first;
    node* second;
    if(!temp || !temp->next )
    {
        cout<<endl<<"When only 1 element is left then function returns"<<endl;
        return;
    }
    find_middle(temp,first,second);
    cout<<" After find_middle runs sucessfully"<<endl;
    merge_sort(first);
    cout<<" After merge sort first runs sucessfully"<<endl;
    merge_sort(second);
    cout<<" After merge sort second runs sucessfully"<<endl;
    head = merge_both(first,second);
    cout<<" After merge_both RUNS and head is changed sucessfully"<<endl;
}
/////////////////DISPLAYS LINK LIST//////////////////
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
////////////INT MAIN//////////////////////
int main ()
{
    node* head=NULL;
    insert_at_head(head,7);
    insert_at_head(head,6);
    insert_at_head(head,9);
    insert_at_head(head,10);
    insert_at_head(head,3);
    insert_at_head(head,1);
    display(head);
    merge_sort(head);
    display(head);
    cout<<endl;
    return 0;
}
