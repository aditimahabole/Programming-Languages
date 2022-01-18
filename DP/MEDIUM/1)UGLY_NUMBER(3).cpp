//UGLY NUMBERS DIVISIBLE BY 2 3 5 
//USING SET
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
int get_ugly(int n)
{
    if(n==1 || n==2|| n==3|| n==4|| n==5)
    {return n;}
    set<int>s;
    s.insert(1);
    n--;
     //The set stores the elements in sorted order.
    //All the elements in a set have unique values.
   //The value of the element cannot be modified once it is added to the set, though it is possible to remove and then add the modified value of that element. Thus, the values are immutable.
//Sets follow the Binary search tree implementation.
//The values in a set are unindexed.
//set<int, greater<int> > s1;(for descending order)
    while(n)
    {
        cout<<"______________"<<endl;
        cout<<"n = "<<n<<endl;
        auto it=s.begin();
        int x=*it;
        cout<<"x = "<<x<<endl;
        cout<<"______________"<<endl;
        cout<<"it erased = "<<*it<<endl;
        s.erase(it);
        cout<<"______________"<<endl;
        
        s.insert(x*2);
        s.insert(x*3);
        s.insert(x*5);
        cout<<x*2<<" "<<x*3<<" "<<x*5<<endl;
        cout<<"______________"<<endl;
        n--;
    }
    return *s.begin();
}
int main() 
{
    int num=8;
    unsigned no=get_ugly(num);
    cout<<num<<"th ugly number is : "<<no;

    return 0;
}
/* OUTPUT :
______________
n = 7
x = 1
______________
it erased = 1
______________
2 3 5
______________
______________
n = 6
x = 2
______________
it erased = 2
______________
4 6 10
______________
______________
n = 5
x = 3
______________
it erased = 3
______________
6 9 15
______________
______________
n = 4
x = 4
______________
it erased = 4
______________
8 12 20
______________
______________
n = 3
x = 5
______________
it erased = 5
______________
10 15 25
______________
______________
n = 2
x = 6
______________
it erased = 6
______________
12 18 30
______________
______________
n = 1
x = 8
______________
it erased = 8
______________
16 24 40
______________
8th ugly number is : 9
*/
