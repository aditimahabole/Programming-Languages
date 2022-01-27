//https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/


class Solution {
public:
  \
    int findTheWinner(int n, int k) 
    {
      queue<int>q;
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        while(q.size()!=1)
        {
            int j=1;
            while(j<k)
            {
               int t=q.front();
                q.pop();
                q.push(t);
                j++;
            }
            q.pop();
        }
        return q.front();
        
        
    }
};
