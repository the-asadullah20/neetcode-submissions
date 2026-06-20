class Solution:
    def bs(self,i,j,target,nums:List[int])->int:
        mid=i+(j-i)//2
        if i>j:
            return -1
        if nums[mid]>target:
            return self.bs(i,mid-1,target,nums)
        if nums[mid]==target:
            return mid
        else:
            return self.bs(mid+1,j,target,nums)
    def search(self, nums: List[int], target: int) -> int:
        i=0
        j=len(nums)-1
        return self.bs(i,j,target,nums)