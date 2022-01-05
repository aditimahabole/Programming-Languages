//UNORDERED MAP USED THAT IS HASHING CONCEPT USED 
//MAP IS LIKE THIS [DATA,COUNT]
//https://www.geeksforgeeks.org/union-intersection-two-linked-lists-set-3-hashing/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
};
void inserts(node*&head,int data)
{
    node* new_node=new node;
    new_node->data=data;
    new_node->next=head;
    head=new_node;
}
void store_elements(node*head1,node*head2,unordered_map<int,int>& ele)
{
    node* temp1=head1;
    node* temp2=head2;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1!=NULL)
        {
            ele[temp1->data]++;//we are storing count at index of element itself suppose 4 is the element so we are storing 1 at 4th position in unordered_mp
            temp1=temp1->next;
        }
        if(temp2!=NULL)
        {
            ele[temp2->data]++;//we are storing count at index of element itself suppose 4 is the element so we are storing 1 at 4th position in unordered_mp
            temp2=temp2->next;
        }
    }
}
node* get_union(unordered_map<int,int>&ele)
{
    node* ans=NULL;
    for(auto i=ele.begin();i!=ele.end();i++)
    {
        inserts(ans,i->first);
    }
    return ans;
}
node* get_intersection(unordered_map<int,int>&ele)
{
    node* ans=NULL;
    for(auto i=ele.begin();i!=ele.end();i++)
    {
        if(i->second==2)
        {
            inserts(ans,i->first);
        }
    }
    return ans;
}
void display(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    node*head1=NULL;
    inserts(head1,5);
    inserts(head1,4);
    inserts(head1,3);
    inserts(head1,2);
    inserts(head1,1);
    node*head2=NULL;
    inserts(head2,6);
    inserts(head2,5);
    inserts(head2,3);
    inserts(head2,1);
    cout<<endl;
    cout<<"LIST 1 : "<<endl;
    display(head1);
    cout<<endl;
    cout<<"LIST 2 : "<<endl;
    display(head2);
    unordered_map<int,int>ele;
    store_elements(head1,head2,ele);
    cout<<endl;
    cout<<"UNION OF LIST 1 and LIST 2 : "<<endl;
    node* uni=get_union(ele);
    cout<<endl;
    display(uni);
    cout<<endl;
    cout<<"INTERSECTION OF LIST 1 and LIST 2 : "<<endl;
    node* in=get_intersection(ele);
    cout<<endl;
    display(in);
    cout<<endl;
    return 0;
}
/*OUTPUT:
LIST 1 : 
1-->2-->3-->4-->5-->NULL

LIST 2 : 
1-->3-->5-->6-->NULL
UNION OF LIST 1 and LIST 2 : 

1-->2-->3-->5-->4-->6-->NULL

INTERSECTION OF LIST 1 and LIST 2 : 

1-->3-->5-->NULL
*/
