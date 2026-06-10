class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        counter=1
        d={}
        nums.sort()
        for i in range(0,len(nums)):
            d[nums[i]]=i
            if counter in d:
                counter+=1
        return counter
            
