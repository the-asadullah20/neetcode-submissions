class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        d={}
        for i in nums:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
        arr=[]
        for key,value in d.items():
            if value>(len(nums)//3):
                arr.append(key)
        return arr