class Solution:
    def dailyTemperatures(self, nums: List[int]) -> List[int]:
        s=[]
        arr=[0]*len(nums)
        for i in range(0,len(nums)):
            while(s and nums[s[-1]]<nums[i]):
                arr[s[-1]]=i-s[-1]
                s.pop()
            s.append(i)
        return arr
            
            