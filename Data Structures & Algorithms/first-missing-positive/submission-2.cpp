class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1;
        for(auto i:nums)
        {
            if(i==ans) ans++;
        }
        return ans;
    }
};