class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i=0
        j=len(heights)-1
        area=float('-inf')
        while(i<j):
            w=j-i
            h=min(heights[i],heights[j])
            area=max(area,w*h)
            if heights[j]>heights[i]:
                i+=1
            elif heights[i]>heights[j]:
                j-=1
            else:
                i+=1
                j-=1
        return area
