// ---------------------------------------------------------------------------------
// Problem:
// In a game there are two players A and B
// A always start first and we have to make A win
// so we are given points array and rule of game is that Player can shoot 
// from ends only and not middle .that is they are allowed to gain points from any end of array.
// and both player play optimally 
// example:
// points = [11,20,2,10]
// output = 30
// in this if A choose 10 first then 
// B left with 11 ,20,2
// and whatever B chooses as he will play smart so can choose 11 
// then A left with 20 , 2
// and now A takes 20 
// and B left with 2 
// so A total is 30 and B total is 13
// so A wins
// Example 2:
// points = [15, 19 ,2, 10]
// output  = 29
// ---------------------------------------------------------------------------------
Code:


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&v,int l,int r,int turn)
{
    int left = 0;
    int right = 0;
    int not_left = 0;
    int not_right = 0;
    if(l==r && !turn) return 0;
    if(l==r && turn) return v[l];
    
    if(turn)
    {
        left = v[l]+solve(v,l+1,r,false);
        right = v[r]+solve(v,l,r-1,false);
    }
    // Instead of always trying to maximize the score we
    // should try to minimize the opponent's score.
    
    // else
    // {
    //     maximizing it and thats not correct way
    //     if(v[l]>v[r]) not_left = solve(v, l+1, r, true);
    //     else not_right = solve(v, l, r-1, true);
    //     return max(not_left, not_right);
    // }
    else {
            int not_left = solve(v, l + 1, r, true);
            int not_right = solve(v, l, r - 1, true);
            return min(not_left, not_right);
        }
    return max(left,right);
}

int main() {
  
    // vector<int> v = {11 ,20, 2, 10 };
    // vector<int> v ={15, 19 ,2, 10};
    // vector<int> v ={20, 11 ,10, 2};
    // vector<int> v ={5, 3, 7, 10};
    // vector<int> v ={8, 15, 3, 7};
    vector<int> v ={20,30,2,2,2,10};
    // vector<int> v ={2,2,2,2};
    int n = v.size();
    cout<<solve(v,0,n-1,true);
    return 0;
}
