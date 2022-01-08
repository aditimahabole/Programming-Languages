//XOR USED

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//TO CHECK IF TWO ARAY ARE EQUAL IS TO XOR 
//IF A^B ==0 THEN THEY ARE EQUAL
bool arr_equal_using_XOR(int arr1[],int arr2[],int n1,int n2)
{
    if(n1!=n2)
    {
        return false;
    }
    int num1=arr1[0];
    int num2=arr2[0];
    cout<<"-----------------------------"<<endl;
    for(int i=1;i<n1;i++)
    {
        cout<<"num1 = "<<num1<<endl;
        cout<<"ar1r[i] = "<<arr1[i]<<endl;
        num1=num1^arr1[i];
        cout<<"num1 for arr1 = "<<num1<<endl;
    }
    cout<<"-----------------------------"<<endl;
    for(int i=1;i<n2;i++)
    {
        cout<<"num2 = "<<num2<<endl;
        cout<<"ar1r[i] = "<<arr1[i]<<endl;
        num2=num2^arr2[i];
        cout<<"num2 for arr2 = "<<num2<<endl;
    }
    cout<<"-----------------------------"<<endl;
    int all_xor=num1^num2;
    cout<<"all xor = "<<all_xor<<endl;
    if(all_xor == 0)
    {
        return true;
    }
    return false;
}

int main() {
    int arr1[] = { 3, 5, 2, 5, 2 };
    int arr2[] = { 2, 3, 5, 5, 2 };
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    if(arr_equal_using_XOR(arr1,arr2,n1,n2))
    {
        cout<<"EQUAL"<<endl;
    }
    else
    {
        cout<<"NOT EQUAL"<<endl;
    }
    return 0;
}
/* OUTPUT : 
/tmp/G0dUpOlbjk.o
-----------------------------
num1 = 3
ar1r[i] = 5
num1 for arr1 = 6
num1 = 6
ar1r[i] = 2
num1 for arr1 = 4
num1 = 4
ar1r[i] = 5
num1 for arr1 = 1
num1 = 1
ar1r[i] = 2
num1 for arr1 = 3
-----------------------------
num2 = 2
ar1r[i] = 5
num2 for arr2 = 1
num2 = 1
ar1r[i] = 2
num2 for arr2 = 4
num2 = 4
ar1r[i] = 5
num2 for arr2 = 1
num2 = 1
ar1r[i] = 2
num2 for arr2 = 3
-----------------------------
all xor = 0
EQUAL
*/
