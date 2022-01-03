// HERE CONCEPT OF GRAPH IS USED 
//VECTORS ARE USED 
//IN DEGREE AND OUT DEGREE CONCEPT IS USED 
//https://leetcode.com/problems/find-the-town-judge/submissions/
#include <iostream>
#include <vector>
using namespace std;
int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inout(n+1, 0);
        
        for(auto t : trust)
        {
            cout<<"value of t[0] : "<<t[0]<<endl;
            cout<<"value of t[1] : "<<t[1]<<endl;
            cout<<"value of inout[t[0]] : "<<inout[t[0]]<<endl;
            cout<<"value of inout[t[1]] : "<<inout[t[1]]<<endl;
            inout[t[0]]--; //outdegree of a node
            cout<<"value of inout[t[0]]-- :  "<<inout[t[0]]<<endl;
            inout[t[1]]++; //indegree of a node
            cout<<"value of inout[t[0]]++ : "<<inout[t[1]]<<endl;
        }
        for(int i=1; i<n+1; i++){   //there are n people labelled from 1 to n
        cout<<"inout[i] : "<<inout[i]<<" i : "<<i<<endl;
            if(inout[i]==n-1) return i;
        }
        return -1;
        
        
    }

int main() {
   vector<vector<int>> trust
   {
       {1,3},
       {2,3}
   };
   int n=3;
    cout<<findJudge(n,trust);
   

    return 0;
}
