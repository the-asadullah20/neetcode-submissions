class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zero=nums.count(0)
        if zero>=2:
            return [0]*len(nums)
        pro=1
        for i in nums:
            if i!=0:
                pro*=i
        idx=-1
        if zero==1:
            for i in range(0,len(nums)):
                if nums[i]==0:
                    idx=i
                    break
            arr=[0]*len(nums)
            arr[idx]=pro
            return arr
        for i in range(0,len(nums)):
            nums[i]=int(pro/nums[i])
        return nums 
