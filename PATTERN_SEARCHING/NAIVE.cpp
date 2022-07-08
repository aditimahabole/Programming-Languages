
// START SEARCHING FROM THE POINT WHERE WE GET UNMATCH
//https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int search(string pat,string txt)
{
    int j=0;
    int plen=pat.length();
    int tlen=txt.length();
    //0 1 2 3 4 5 6 7-->i
    //A A B C A A B A
    //0 1 2 3 -->j
    //A A B A
    for(int i=0;i<tlen;i++)
    {
        cout<<"----------------------------"<<endl;
        cout<<"txt["<<i<<"] = "<<txt[i]<<endl;
        cout<<"pat["<<j<<"] = "<<pat[j]<<endl;
        cout<<"----------------------------"<<endl;
        if(txt[i]==pat[j])
        {
            j++;
            cout<<"j increased "<<j<<endl;
        }
        
        else
        {
            cout<<"inside else"<<endl;
            if(j>0)
            {
                i--;
                cout<<"i decreased "<<i<<endl;
                
                //i-- karne ke baad loop ki wajha se i++ hoga
                //so hum uss last posi jaha match nhihua wahi 
                //pe rahege
                // A A B yaha tak match hua C pe nhi hau to ab hum C se match karna shuru karenge
            }
            j=0;
        }
        if(j==plen)
        {
            cout<<"returned "<<endl;
            return (i-plen +1);
        }
    }
    return -1;
}


int main()
{
    string txt="AABCAABA";
    string pat="AABA";
    cout<<search(pat,txt);
   

    return 0;
}
/*
/tmp/sY3UKRG1Do.o
----------------------------
txt[0] = A
pat[0] = A
----------------------------
j increased 1
----------------------------
txt[1] = A
pat[1] = A
----------------------------
j increased 2
----------------------------
txt[2] = B
pat[2] = B
----------------------------
j increased 3
----------------------------
txt[3] = C
pat[3] = A
----------------------------
inside else
i decreased 2
----------------------------
txt[3] = C
pat[0] = A
----------------------------
inside else
----------------------------
txt[4] = A
pat[0] = A
----------------------------
j increased 1
----------------------------
txt[5] = A
pat[1] = A
----------------------------
j increased 2
----------------------------
txt[6] = B
pat[2] = B
----------------------------
j increased 3
----------------------------
txt[7] = A
pat[3] = A
----------------------------
j increased 4
returned 
4
*/
