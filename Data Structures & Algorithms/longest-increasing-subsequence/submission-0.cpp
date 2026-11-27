class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        for(int x:nums)
        {
            int i=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
            if(i==dp.size())
            {
                dp.push_back(x);
            }
            else
            {
                dp[i]=x;
            }
        }
        return dp.size();
    }
};
