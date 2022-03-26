// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define MAX_SIZE 100
using namespace std;
class huffman_node
{
    public:
    char data;
    int fre;
    huffman_node *left;
    huffman_node *right;
    huffman_node(char c,int f)
    {
        data=c;
        fre=f;
        left=right=NULL;
    }
};

class compare
{
    public:
    bool operator()(huffman_node *a,huffman_node *b)
    {
        return a->fre>b->fre;
    }
    
};

huffman_node*make_tree(priority_queue<huffman_node*,vector<huffman_node*>,compare> pq)
{
    while(pq.size()!=1)
    {
        huffman_node* left=pq.top();
        pq.pop();
        huffman_node* right=pq.top();
        pq.pop();
        huffman_node* node=new huffman_node('@',left->fre+right->fre);
        node->left=left;
        node->right=right;
        pq.push(node);
    }
}
void print_codes(huffman_node* root,int arr[],int top)
{
    if(root->left)
    {
        arr[top]=0;
        print_codes(root->left,arr,top+1);
    }
     if(root->right)
    {
        arr[top]=1;
        print_codes(root->right,arr,top+1);
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->data<<" ";
        for(int i=0;i<top;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
    
    
}

void huffman_ke_codes(char data[],int fre[],int n)
{
priority_queue<huffman_node*,vector<huffman_node*>,compare>pq;
    for(int i=0;i<n;i++)
    {
        huffman_node* new_node=new huffman_node(data[i],fre[i]);
        pq.push(new_node);
        
    }
    huffman_node *root=make_tree(pq);
    int arr[MAX_SIZE],top=0;
    print_codes(root,arr,top);
}


int main() 
{
    char data[]={'a','b','c','d','e','f'};
    int fre[]={5,9,12,13,16,45};
    int n=sizeof(data)/sizeof(data[0]);
    huffman_ke_codes(data,fre,n);
   

    return 0;
}
