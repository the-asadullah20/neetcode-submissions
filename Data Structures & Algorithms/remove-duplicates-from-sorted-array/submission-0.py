class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not len(nums):
            return 0
        prev=nums[0]
        i=1
        c=1
        while i<len(nums):
            while i<len(nums) and nums[i]==prev:
                i+=1
            if i<len(nums):
                prev=nums[i] 
                nums[c]=prev
                i+=1
                c+=1
        return c

