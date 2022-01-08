// https://www.geeksforgeeks.org/count-items-common-lists-different-prices/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class item
{
    public:
    
    string name;
    int price;
};

int count_item(item l1[],item l2[],int n1,int n2)
{
    unordered_map<string,int> op;
    int count=0;
    for(int i=0;i<n1;i++)
    {
        op[l1[i].name]=l1[i].price;
    }
    
    for(int i=0;i<n2;i++)
    {
       if(op.find(l2[i].name)!=op.end() && op[l2[i].name]!=l2[i].price)
        {
            count++;
        }
    }
    return count;
   
}
int main() 
{
item list1[] = {{"apple", 60}, {"bread", 20},
                 {"wheat", 50}, {"oil", 30}};
item list2[] = {{"milk", 20}, {"bread", 15},
                {"wheat", 40}, {"apple", 60}};
    int n1 = sizeof(list1) / sizeof(list1[0]);
    int n2 = sizeof(list2) / sizeof(list2[0]);
    
    cout<<count_item(list1,list2,n1,n2)<<" = count"<<endl;
    return 0;
}
