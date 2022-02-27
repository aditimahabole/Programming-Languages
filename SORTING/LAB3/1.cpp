
#include <iostream>
using namespace std;
int cube(int n)
{
    return n*n*n;
}

int cube_root(int n,int l,int h)
{
    if(l<=h)
    {
        int mid=(h+l/2);
        int c=cube(mid);
        if(c==n)
        {
            return mid;
        }
        else if(c>n)
        {
            return cube_root(n,l,mid-1);
        }
        else 
        {
            return cube_root(n,mid+1,h);
        }
    }
}
//using binary search time complexity  will be log n base 3
int main() {
int n=216;
cout<<cube_root(n,0,n);
return 0;
}
