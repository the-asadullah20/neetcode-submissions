class Solution:
    def trap(self, nums: List[int]) -> int:
        n=len(nums)
        l=[0]*len(nums)
        r=[0]*len(nums)
        l[0]=nums[0]
        r[n-1]=nums[n-1]
        for i in range(1,n):
            l[i]=max(l[i-1],nums[i])
        for i in range(n-2,-1,-1):
            r[i]=max(r[i+1],nums[i])
        water=0
        for i in range(0,n):
            water+=min(l[i],r[i])-nums[i]
        return water