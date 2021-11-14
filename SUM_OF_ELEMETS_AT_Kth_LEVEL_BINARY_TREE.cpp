#include <iostream>
#include <queue>

using namespace std;
class node
{
public:
    int data;
    node*left;
    node* right;
};
///////////MAKING NEW NODE/////////
node* make_node(int value)
{
    node*new_node=new node;
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
//////////SUM at Kth LEVEL///////////////
int sum_at_k(node* root,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    queue<node*> q;
    queue<int> q1;
    q.push(root);
    q.push(NULL);
    q1.push(root->data);
    q1.push(NULL);
    int level=1;
    int sum=0;
    cout<<"root->data  :  "<<root->data<<endl;

    while(!q.empty() )
    {
        node*temp=q.front();
        q.pop();
        //cout<<"q.front  :  "<<temp->data<<endl;
        if(temp!=NULL)
        {
            if(level==k)
            {
                sum+=temp->data;
                cout<<temp->data<<" +  "<<"  =  "<<sum<<endl;
            }
            if(temp->left)
            {
                q.push(temp->left);
                q1.push(temp->left->data);
                cout<<"temp->left  :  "<<temp->left->data<<endl;
            }
            if(temp->right)
            {
                q.push(temp->right);
                q1.push(temp->right->data);
                cout<<"temp->right :  "<<temp->right->data<<endl;
            }
        }
        else if(temp==NULL &&!q.empty())
        {
            q.push(NULL);
            q1.push(NULL);
            level++;
        }
        //example: 1 NULL 2 3 NULL 4 5 6 7 NULL 8 9 10 11 12 13 14 15 NULL
        //this is how queue will look like
   }
   cout<<"QUEUE : "<<endl;
   while(!q1.empty())
   {
       cout<<q1.front()<<"   ";
       q1.pop();
   }
   cout<<endl<<"HERE 0 INDICATES THE END OF LEVEL "<<endl;
   cout<<endl;

   return sum;
}

int main()
{
     node* root=NULL;
    /*            1
             /         \
          2              3
        /  \            /  \
      4      5        6      7
    / \     /\       /\      /\
   8   9  10  11   12 13  14  15
*/
    root=make_node(1);
    root->left=make_node(2);
    root->right=make_node(3);
    root->left->left=make_node(4);
    root->left->right=make_node(5);
    root->right->left=make_node(6);
    root->right->right=make_node(7);
    root->left->left->left=make_node(8);
    root->left->left->right=make_node(9);
    root->left->right->left=make_node(10);
    root->left->right->right=make_node(11);
    root->right->left->left=make_node(12);
    root->right->left->right=make_node(13);
    root->right->right->left=make_node(14);
    root->right->right->right=make_node(15);
    cout<<endl;
    int k;
    cout<<"ENTER THE Kth LEVEL:"<<endl;
    cin>>k;
    cout<<"SUM OF NODES AT "<<k<<" LEVEL ID  :  "<<sum_at_k(root,k);

    cout<<endl<<"CODE BY CHUNNU BOLA(Aditi Mahabole)"<<endl;
    return 0;
}
