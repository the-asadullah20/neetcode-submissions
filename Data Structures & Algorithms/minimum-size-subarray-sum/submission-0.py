class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        mini=float('inf')
        s=0
        j=0
        for i in range(0,len(nums)):
            s+=nums[i]
            if s>=target:
                mini=min(mini,i-j+1)
            while s>=target:
                s-=nums[j]
                mini=min(mini,i-j+1)
                j+=1
                

        if sum(nums)<target and mini==float('inf'):
            return 0
        return mini