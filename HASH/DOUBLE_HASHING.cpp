//OPEN ADDRESSING 
#include <iostream>
using namespace std;
#define table_size 13 //you can change size accroding to you number of data
#define  prime 7 // take a prime number just less than the size of table LIKE if size is 10 then take prime 7 ,if size 35 then take prime =31

class double_hash
{
    int* hash_table;
    int curr_size;
    public:
    ////////DEFAULT CONSTRUCTOR////////
    double_hash()
    {
        hash_table=new int[table_size];
        curr_size=0;
        for(int i=0;i<table_size;i++)
        {
            hash_table[i]=-1;
        }
        
    }
    ////////TO CHECK IF TABLE IS FULL OR NOT /////
    bool is_full()
    {
        return (curr_size==table_size);
    }
    ///////////HASH1 FUNCTION //////////////
    int hash1(int data)
    {
        return(data % table_size);
    }
    ///////////HASH2 FUNCTION //////////////    
    int hash2(int data)
    {
        return(prime - (data % prime));
    }
    ///////////INSERT FUNCTION /////////////
    void insert_item(int data)
    {
        if(is_full())
        {
            return;//this checks when table is full then simply return as we cannot insert now no space left
        }
        
        int index1=hash1(data);
        if(hash_table[index1]!=-1)//if by using hash1 we do not get vacant place then we use double hash funtion
        {
            int index2=hash2(data);
            int i=1;
            
            while(1)
            {
                int index3=(index1 + i*index2)%table_size;//formula for double hashing
                if(hash_table[index3]== -1)//means vacant space 
                {
                    hash_table[index3]=data;//data inserted
                    break;//break after insert from loop
                }
                i++;
            }
        }
        
        else//if by using hash1 only we get vacant space  then simply insert
        {
            hash_table[index1]=data;
            curr_size++;
        }
    }
    ///////////////SEARCH//////////
    void search(int data)
    {
        int i=0;
        int index1=hash1(data);
        int index2=hash2(data);
        int index3=(index1+ i*index2)%table_size;
        
        while(hash_table[index3]!=data)
        {
            if(hash_table[index3]==-1)
            {
                cout<<data<<" Does not exist !"<<endl;
                return;
            }
            i++;
        }
        cout<<data<<" Found at index "<<index3<<endl;
        
    }
    void display()
    {
        for(int i=0;i<table_size;i++)
        {
            if(hash_table[i]!=-1)
            {
                cout<<i<<" ---> "<<hash_table[i]<<endl;
            }
            else
            {
                cout<<i<<endl;
            }
        }
    }

    
};
int main() 
{
    int arr[]={19,27,36,10,64};
    int n=sizeof(arr)/sizeof(arr[0]);
    double_hash h;//object
    
    for(int i =0 ;i<n;i++)
    {
        h.insert_item(arr[i]);
    }
    cout<<endl;
    h.search(36);
    h.search(100);
    h.search(19);
    cout<<endl;
    h.display();
    cout<<endl;
    cout<<"CODE BY ADITI MAHABOLE(CHUNNU BOLA)"<<endl;
    
   

    return 0;
}
