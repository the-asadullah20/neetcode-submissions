class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        vector<int>nsr(n,n);
        vector<int>nsl(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                nsr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && nums[s.top()]>nums[i])
            {
                nsl[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,(nsr[i]-nsl[i]-1)*nums[i]);
        }
        return maxi;
    }
};
