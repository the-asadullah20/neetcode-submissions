class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d={}
        for i in nums:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
        maxi=float('-inf')
        ans=float('-inf')
        for key,value in d.items():
            if value>maxi:
                ans=key
                maxi=value
        return ans