class Solution {
public:
    vector<int>ans;
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        int n = nums.size();
        vector<int>make_box;
        int one = pow(2,maximumBit) - 1;
        int make = (0<<(maximumBit -1));
        for(int i=0;i<n;i++)
        {
            nums[i]= (nums[i]|make);
        }
         int Xor=0;
        for(int i=n-1;i>=0;i--)
        {
            Xor =0;
            for(int j=0;j<=i;j++)
            {
                Xor = Xor ^ nums[j];
            }
           make_box.push_back(Xor ^ one);
        }
        return make_box ;
    }
};
