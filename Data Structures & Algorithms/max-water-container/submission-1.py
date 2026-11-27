class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxi=0
        i=0
        j=len(heights)-1
        while i<j:
            mini=min(heights[i],heights[j])
            maxi=max(maxi,mini*(j-i))
            if heights[i]>heights[j]:
                j-=1
            elif heights[i]<heights[j]:
                i+=1
            else:
                i+=1
                j-=1
        return maxi
