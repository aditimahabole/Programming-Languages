//HASING IS USED AND SO TIME COMPLEXITY FOR SEARCHING IS O(1) AND 
//TRAVERSING ARR2[] IS SIZE OF IT SO TIME COMPLEXITY VERY MUCH REDUCED
//RAW CODE WRITTEN EASILY UNDERSTANDABLE
//CHAINING INT HASHING  CONCEPT IS USED 

#include <bits/stdc++.h>
#include <list>
using namespace std;
class Hash
{
    public:
    int bucket;
    list<int> *table;
    Hash(int b)
    {
        bucket=b;
        table= new list<int>[bucket];
    }


int hash_func(int item)
{
    return (item % bucket);
    //returns index 
}
void insert_item(int data)
{
    int index=hash_func(data);//index stored
    table[index].push_back(data);//inserted to link list
}
void delete_item(int data)
{
    int index=hash_func(data);//find index of data first
    list<int> :: iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)//search data
    {
        if(*i==data)
        {
            break;//break if key is found now its time to remove it
        }
    }
    if(i!=table[index].end())//if data found then erase from link list
    {
        table[index].erase(i);
    }
}
bool search_item(int data)
{
    int index=hash_func(data);//find index of data first
    list<int> :: iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)//search data
    {
        if(*i==data)
        {
            return true;
        }
    }
    
    return false;

    
}
void display_hash()//to display 
{
    for(int i =0 ;i<bucket;i++)
    {
        cout<<i;//index printed
        for(auto x : table[i])
        {
            cout<<" ---> "<<x;//link list printed
        }
        cout<<endl;
    }
}
void is_subset(int arr1[],int arr2[],int arr1_size,int arr2_size)
{
  
   for(int i=0;i<arr2_size;i++)
   {
      if(!search_item(arr2[i]))
      {
          cout<<"not a subset"<<endl;
          break;
      }
      
       
   }
  
    cout<<"arr2[] is a subset of arr1[]"<<endl;
   
}

};

int main()
{

	int arr1[] = { 11, 1, 13, 21, 3, 7 };
    int arr2[] = { 11, 3, 7, 1 };
    int arr1_size=sizeof(arr1) / sizeof(arr1[0]);
    int arr2_size=sizeof(arr2) / sizeof(arr2[0]);
	int b=arr1_size + 1;
// 	cout<<"ENTER SIZE OF BUCKET : "<<endl;
// 	cin>>b;
	Hash h(b);
	for(int i=0;i<arr1_size;i++)
    {
        h.insert_item(arr1[i]);
    }
    
    h.is_subset(arr1,arr2,arr1_size,arr2_size);
  cout<<"code by ADITI MAHABOLE(chunnu bola)"<<endl;

	return 0;
}
//OUTPUT FOR THIS : arr2[] is a subset of arr1[]


