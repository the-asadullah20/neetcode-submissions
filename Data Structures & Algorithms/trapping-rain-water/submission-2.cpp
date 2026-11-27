class Solution {
public:
    int trap(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        vector<int>r(n);
        vector<int>l(n);
        l[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            l[i]=max(l[i-1],nums[i]);
        }
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            r[i]=max(nums[i],r[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            maxi+=min(l[i],r[i])-nums[i];
        }
        return maxi;
    }
};
