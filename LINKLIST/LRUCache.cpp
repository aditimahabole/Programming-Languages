
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    
    int key;
    int data;
    Node* next;
    Node* prev;
    
    Node(int key , int data){
        this->data = data;
        this->key = key;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LRUCache{
    private:
    int capacity;
    unordered_map<int,Node*>cache;
    Node* head;
    Node* tail;
    
    void remove_node(Node* node){
        
        if(node->prev) node->prev->next = node->next;
        else head = node->next;
        
        if(node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }
    
    void insert_at_head(Node* node){
        node->next = head;
        node->prev = NULL;
        
        if(head){
            head->prev = node;
        }
        head = node;
        
        if(tail == NULL) tail = head;
    }
    
    public:
    
    LRUCache(int capacity){
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key){
        if(cache.find(key)==cache.end()) return -1;
        
        Node* node = cache[key];
        remove_node(node);
        insert_at_head(node);
        return node->data;
    }
    
    void put(int key,int val){
        
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            node->data = val;
            remove_node(node);
            insert_at_head(node);
        }
        else{
           
            if(cache.size() == capacity){
            cout<<"Cache size exceeds : "<<cache.size()<<endl;
            cout<<"Remove Tail key : "<<tail->key<<endl;
                cache.erase(tail->key);
                
                remove_node(tail);
                display();
                cout<<"-----------"<<endl;
            }
            
            Node* node = new Node(key,val);
            insert_at_head(node);
            cache[key] = node;
        }
    }
    
    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "(" << temp->key << "," << temp->data<< ") ";
            temp = temp->next;
        }
        cout << endl;
    }
    
};



int main() {
    
    LRUCache cache(3);
    
    cache.put(1,1);
    cache.display();
    cache.put(2,2);
    cache.display();
    cache.put(3,3);
    cache.display();
    
    cache.put(4,4);
    cache.display();
   cache.put(5,5);
   cache.display();
   cache.put(4,2);
   cache.display();
   cache.get(3);
   cache.display();
   

    return 0;
}
