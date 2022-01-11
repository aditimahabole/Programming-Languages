//https://www.geeksforgeeks.org/second-repeated-word-sequence/
// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// string get_key(string s)
// {
//     bool visited[26]={false};
//     for(int i=0;i<s.length();i++)
//     {
//         visited[s[i]-'a']=true;
//     }
//     string key="";
//     for(int i=0;i<26;i++)
//     {
//         if(visited[i])
//         {
//             key=key+char('a'+i);
//         }
//     }
//     return key;
// }
int sor(pair<string,int>a,pair<string,int>b)
{
    return a.second<b.second;
}

string second_max(string arr[],int n)
{
    unordered_map<string,int>m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
        
    }
    vector<pair<string,int>>v(m.begin(),m.end());
    sort(v.begin(),v.end(),sor);
    
   return v[1].first;
}


int main()
{
    // string arr[]={"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};
    string arr[]={"geeks", "for", "geeks", "for", "geeks", "aaa"};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"string is : "<<second_max(arr,n);
    return 0;
}
// OUTPUR : string is : for
