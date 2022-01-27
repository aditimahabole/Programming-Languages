//MOST EFFICIENT
class Solution {
public:
    void reverse(vector<int>&nums,int low,int high)
    {
        while(low<high)
        {
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
        
    }
};
/* EX 1 2 3 4 5 6 7
FIRST REVERSE ELEMENTS FROM 0 TO N-K-1 THAT IS N=7 AND K=2
TO REVERSE FROM 0 TO 7-2-1=4TH 
0 1 2 3 4
1 2 3 4 5
AFTER REVERSING 
5 4 3 2 1
NOW REVERSE THE OTHER SET THT IS FROM N-K TO N-1
N-K=7-2=5 AND N-1=7-1=6
5 6
6 7
AFTER REVERSAL 
7 6
NOW ARRAY LOOKS LIKE THIS 
5 4 3 2 1 7 6
NOW AGAIN REVERSE THE WHOLE ARRAY 
6 7 1 2 3 4 5
AND THIS WILL BE YOUR FINAL ANSWER 
//https://youtu.be/ENcnXXiRT6E
SEE THIS VIDEO 
*/
