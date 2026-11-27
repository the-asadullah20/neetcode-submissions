class Solution {
public:
vector<int>temp;
vector<vector<int>>ans;
void solve(int i,vector<int>&nums,int target)
{
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    if(target<0 || i==nums.size()) return;
    temp.push_back(nums[i]);
    solve(i,nums,target-nums[i]);
    temp.pop_back();
    solve(i+1,nums,target);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(0,nums,target);
        return ans;
    }
};
