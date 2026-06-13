class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d={}

        for i in nums:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1
        sd=dict(sorted(d.items(),key=lambda x:x[1], reverse=1))
        arr=[]
        for key,value in sd.items():
            if k>0:
                arr.append(key)
            k-=1
        return arr
        
