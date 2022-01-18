//UGLY NUMBERS DIVISIBLE BY 2 3 5 
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
int max_divide(int num,int prime)
{
    while(num%prime==0)
    {
        num=num/prime;
    }
    return num;//suppose number is 49 so 2 ,3,5 wont divide 
    //so num will remain 49 only and not 1 
    //so when returned to is_ugly 0 is returned
}
int is_ugly(int num)
{
    num=max_divide(num,2);
    num=max_divide(num,3);
    num=max_divide(num,5);
    if(num==1)
    {
        return 1;
        //id divided by 2, or 3, or 5  only then its true
    }
    else 
    {
        return 0;
    }
}
int get_ugly(int n)
{
    int i=1;
    int count=1;
    while(count<n)
    {
        i++;//we did i++ beacuse 1 is already includede
        if(is_ugly(i))
        {
            count++;
        }
    }
    return i;
}
int main() 
{
    int num=10;
    unsigned no=get_ugly(num);
    cout<<num<<"th ugly number is "<<no;

    return 0;
}
