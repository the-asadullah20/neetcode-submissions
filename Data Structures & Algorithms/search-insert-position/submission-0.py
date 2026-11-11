def bs(low,high,nums,k):
    if low>high:
        return low
    mid=low+(high-low)//2
    if nums[mid]==k:
        return mid
    elif nums[mid]>k:
        return bs(low,mid-1,nums,k)
    else:
        return bs(mid+1,high,nums,k)

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        return bs(0,len(nums)-1,nums,target)