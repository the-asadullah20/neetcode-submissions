class Solution:
    def solve(self,g,word,i,j,idx,vis):
        if idx==len(word):
            return True

        if i<0 or j<0 or i>=len(g) or j>=len(g[0]):
            return False

        if vis[i][j] or g[i][j]!=word[idx]:
            return False

        vis[i][j]=1

        if self.solve(g,word,i+1,j,idx+1,vis):return True
        if self.solve(g,word,i-1,j,idx+1,vis):return True
        if self.solve(g,word,i,j+1,idx+1,vis):return True
        if self.solve(g,word,i,j-1,idx+1,vis):return True

        vis[i][j]=0
        return False

    def exist(self,g,word):
        n=len(g)
        m=len(g[0])
        vis=[[0]*m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                if self.solve(g,word,i,j,0,vis):
                    return True
        return False