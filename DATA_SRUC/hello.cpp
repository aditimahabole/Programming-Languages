class Solution {
public:
    
    void solve(int x, vector<int> &c, vector<int> &v_k, int &ans)
    {
        if(x>=c.size()){
            int temp = INT_MIN;
            for(int i=0; i<v_k.size(); i++){
                temp = max(temp,v_k[i]); //here we want the max cookie that a children have
            } 
            ans = min(ans,temp);
            return;
        }
        
        //in this we are giving equally possiblites to all children of every bag cookie
        //dry run
        //[8,15,10,20,8], k=2;
        //int 1st iteration 
        // 0     1    (k==2)
        // 8
        // 15
        // 10
        // 20
        // 8 
        // then 8 will backtrack and now it will go to 1
        // it will look like this 
        // 0     1
        // 8     8
        // 15
        // 10
        // 20
        // now 20 will backtrack because 8 has already visited all the childs
         // it will keep happenig and in end we will get the min diff;
        for(int i=0; i<v_k.size(); i++){
            v_k[i] += c[x];
            solve(x+1,c,v_k,ans);
            v_k[i] -= c[x];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int ans = INT_MAX; //we taking it as inf becuase we want the min diff btw each children
        vector<int> v_k(k,0); //initally all children have 0 cookies;
        solve(0,cookies,v_k,ans);
        return ans;
    }
};
