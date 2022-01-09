// https://www.geeksforgeeks.org/find-permuted-rows-given-row-matrix/

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
void common_ele_in_all_row(int a[][4],int r,int c,int row)
{
    unordered_set<int>s;
    vector<int> v;
    int k=0;
    for(int i=0;i<c;i++)
    {
        s.insert(a[row][i]);
    }
    for(int i=0;i<r;i++)
    {k=0;
        if(i!=row)
        {
            for(int j=0;j<c;j++)
            {
                if(s.find(a[i][j])!=s.end())
                {
                    k++;
                }
                if(k==c)
                {
                    v.push_back(i);
                }
            }
        }
    }
    cout<<"--------------------------"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"  ";
    }
    cout<<endl;
    cout<<"--------------------------"<<endl;
}

int main()
{
int c=4;
int a[][4]=
{
   {3, 1, 4, 2}, 
   {1, 6, 9, 3},
   {1, 2, 3, 4},
   {4, 3, 2, 1}
};
int row=3;
int r=sizeof(a)/sizeof(a[0]);
common_ele_in_all_row(a,r,c,row);
    return 0;
}
/*
OUTPUT:
--------------------------
0  2  
--------------------------

*/
