def twosum(i,j,nums,target):
    arr=[]
    nums=nums[i:j+1]
    j=len(nums)-1
    i=0
    while i<j:
        if nums[i]+nums[j]==target:
            arr.append([nums[i],nums[j]])
            i+=1
            j-=1
        elif nums[i]+nums[j]>target:
            j-=1
        else:
            i+=1
    return arr

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans=set()
        for i in range(0,len(nums)-2):
            target=0-nums[i]
            arr=twosum(i+1,len(nums)-1,nums,target)
            for pair in arr:
                ans.add((nums[i],pair[0],pair[1]))
        return [list(x) for x in ans]