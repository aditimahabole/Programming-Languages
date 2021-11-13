#include <iostream>
using namespace std;
//////CREATE NODE/////////
class node
{
public:
    char data;
    node* next;
};
/////////DELETE FIRST NODE////////
node*delete_first(node* &head)
{
    node*temp=head;
    head=head->next;
    delete temp;
    return head;

}
//////////FUNTION FOR DELETING VOWEL//////
void delete_vowel(node* &head)
{

    while(head!=NULL)
    {
        if(head->data=='a'||head->data=='e'||head->data=='i'||head->data=='o'||head->data=='U'||head->data=='A'||head->data=='E'||head->data=='I'||head->data=='O'||head->data=='u')
        {
            head=delete_first(head);

        }
        else
        {
            break;
        }


    }
    node*temp=head;
    while(temp->next!=NULL)
    {
        if(temp->next->data=='a'||temp->next->data=='e'||temp->next->data=='i'||temp->next->data=='o'||temp->next->data=='u'||temp->next->data=='A'||temp->next->data=='E'||temp->next->data=='I'||temp->next->data=='O'||temp->next->data=='U')
        {
            node* to_del=temp->next;
            temp->next=temp->next->next;
            delete to_del;
        }
        else
        {
            temp=temp->next;
        }
    }
}
///////////INSERTING AT END IN LINK LIST////////////
void insert_at_tail(node * &head,char value)
    {
        node*new_node=new node;
        new_node->data=value;
        new_node->next=NULL;
          if(head==NULL)
    {
        head=new_node;
        return;
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
/////////DISPLAYS LINNK LIST////////
    void display(node* &head)
    {
        node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL";
        cout<<endl;
    }
////////////INT MAIN/////////////////
int main()
{
    node*head=NULL;;
        string name;
        cout<<"Enter your name:"<<endl;
        getline(cin,name);
        for(int i=0;i<name.size();i++)
        {
            insert_at_tail(head,name[i]);
        }
        display(head);
        delete_vowel(head);
        display(head);

    return 0;
}

