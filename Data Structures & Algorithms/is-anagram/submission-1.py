class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
            return False
        d1={}
        d2={}
        for i,j in zip(s,t):
            if i not in d1:
                d1[i]=1
            else:
                d1[i]+=1
            if j not in d2:
                d2[j]=1
            else:
                d2[j]+=1
        return d1==d2