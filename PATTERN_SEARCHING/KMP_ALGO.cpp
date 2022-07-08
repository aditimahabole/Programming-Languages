// Online C++ compiler to run C++ program online
//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void make_lps_table(string pat,vector<int>&lps,int plen)
{
    int len=0;
    lps[0]=0;
    //AAAACAAA
    int i=1;
    while(i<plen)
    {
        cout<<"-------------------------------------"<<endl;
        cout<<"pat[i] = "<<pat[i]<<" i = "<<i<<endl;
        cout<<"pat[len] = "<<pat[len]<<" len = "<<len<<endl;
        cout<<"-------------------------------------"<<endl;
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            cout<<"len = "<<len<<endl;
            if(len!=0)
            {
                
                len=lps[len - 1];
            }
            
            else if(len==0)
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmp_search(string pat,string txt)
{
    int j=0;
    int plen=pat.length();
    int tlen=txt.length();
    vector<int>lps(plen,0);
    make_lps_table(pat,lps,plen);
    // for(int i=0;i<plen;i++)
    // {
    //     cout<<pat[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<lps.size();i++)
    // {
    //     cout<<lps[i]<<" ";
    // }
    // cout<<endl;
    
    int i=0;//index for txt
    int j=0;//index for pat
    while(i<tlen)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
            
        }
        if(j==plen)
        {
            cout<<"found at"<<i-j<<endl;
            j=lps[j-1];
        }
        
        else if(i<tlen && pat[j]!=txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
  return 0;
}


int main()
{
    string txt="AABCAABA";
    string pat="ABA";

    kmp_search(pat,txt);
   

    return 0;
}
