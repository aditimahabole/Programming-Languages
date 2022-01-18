//https://www.geeksforgeeks.org/ugly-numbers/
//UGLY NUMBERS DIVISIBLE BY 2 3 5 
//dynamic programing used
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;
int get_ugly(int n)
{
    int ugly[n];
    int i2=0,i3=0,i5=0;
    int next_mul_of_2=2;
    int next_mul_of_3=3;
    int next_mul_of_5=5;
    int next_ugly=1;
    ugly[0]=1;
    for(int i=1;i<n;i++)
    {
        cout<<"________________________________"<<endl;
        cout<<"next_mul_of_2 = "<<next_mul_of_2<<endl;
        cout<<"next_mul_of_3 = "<<next_mul_of_3<<endl;
        cout<<"next_mul_of_5 = "<<next_mul_of_5<<endl;
        cout<<"________________________________"<<endl;
        next_ugly=min(next_mul_of_2,min(next_mul_of_3,next_mul_of_5));
        cout<<"________________________________"<<endl;
        cout<<" min next ugly = "<<next_ugly<<endl;
        ugly[i]=next_ugly;
        cout<<"ugly["<<i<<"] = "<<ugly[i]<<endl;
        cout<<"________________________________"<<endl;
        if(next_ugly==next_mul_of_2)
        {
            i2++;
            next_mul_of_2=ugly[i2]*2;
            cout<<"________________________________"<<endl;
            cout<<"i2 = "<<i2<<endl;
            cout<<"ugly["<<i2<<"]*2 = next_mul_of_2"<<endl;
            cout<<"next_mul_of_2 = "<<next_mul_of_2<<endl;
            cout<<"________________________________"<<endl;
            //hum pehle hi store karke rakh rhe haiii 
            //jese agar i=2 hai to i2++hoga that is 1
            //so i2=1 and i2*2 = 2 so ugly[1]=2
        }
        if(next_ugly==next_mul_of_3)
        {
            i3++;
            next_mul_of_3=ugly[i3]*3;
              cout<<"________________________________"<<endl;
            cout<<"i3 = "<<i3<<endl;
            cout<<"ugly["<<i3<<"]*3 = next_mul_of_3"<<endl;
            cout<<"next_mul_of_3 = "<<next_mul_of_3<<endl;
            cout<<"________________________________"<<endl;
        }
        if(next_ugly==next_mul_of_5)
        {
            i5++;
            next_mul_of_5=ugly[i5]*5;
              cout<<"________________________________"<<endl;
            cout<<"i5 = "<<i5<<endl;
            cout<<"ugly["<<i5<<"]*5 = next_mul_of_5"<<endl;
            cout<<"next_mul_of_5 = "<<next_mul_of_5<<endl;
            cout<<"________________________________"<<endl;
        }
    }
    return next_ugly;
}
int main() 
{
    int num=8;
    unsigned no=get_ugly(num);
    cout<<num<<"th ugly number is : "<<no;

    return 0;
}
/*OUTPUT:
________________________________
next_mul_of_2 = 2
next_mul_of_3 = 3
next_mul_of_5 = 5
________________________________
________________________________
 min next ugly = 2
ugly[1] = 2
________________________________
________________________________
i2 = 1
ugly[1]*2 = next_mul_of_2
next_mul_of_2 = 4
________________________________
________________________________
next_mul_of_2 = 4
next_mul_of_3 = 3
next_mul_of_5 = 5
________________________________
________________________________
 min next ugly = 3
ugly[2] = 3
________________________________
________________________________
i3 = 1
ugly[1]*3 = next_mul_of_3
next_mul_of_3 = 6
________________________________
________________________________
next_mul_of_2 = 4
next_mul_of_3 = 6
next_mul_of_5 = 5
________________________________
________________________________
 min next ugly = 4
ugly[3] = 4
________________________________
________________________________
i2 = 2
ugly[2]*2 = next_mul_of_2
next_mul_of_2 = 6
________________________________
________________________________
next_mul_of_2 = 6
next_mul_of_3 = 6
next_mul_of_5 = 5
________________________________
________________________________
 min next ugly = 5
ugly[4] = 5
________________________________
________________________________
i5 = 1
ugly[1]*5 = next_mul_of_5
next_mul_of_5 = 10
________________________________
________________________________
next_mul_of_2 = 6
next_mul_of_3 = 6
next_mul_of_5 = 10
________________________________
________________________________
 min next ugly = 6
ugly[5] = 6
________________________________
________________________________
i2 = 3
ugly[3]*2 = next_mul_of_2
next_mul_of_2 = 8
________________________________
________________________________
i3 = 2
ugly[2]*3 = next_mul_of_3
next_mul_of_3 = 9
________________________________
________________________________
next_mul_of_2 = 8
next_mul_of_3 = 9
next_mul_of_5 = 10
________________________________
________________________________
min next ugly = 8
ugly[6] = 8
________________________________
________________________________
i2 = 4
ugly[4]*2 = next_mul_of_2
next_mul_of_2 = 10
________________________________
________________________________
next_mul_of_2 = 10
next_mul_of_3 = 9
next_mul_of_5 = 10
________________________________
________________________________
 min next ugly = 9
ugly[7] = 9
________________________________
________________________________
i3 = 3
ugly[3]*3 = next_mul_of_3
next_mul_of_3 = 12
________________________________
8th ugly number is : 9
*/
