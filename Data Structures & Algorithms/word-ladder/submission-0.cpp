class Solution {
public:
bool check(string a,string b)
{
    if(a.length()!=b.length()) return false;
    int c=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
        {
            c+=1;
        }
    }
    return c==1;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>m;
        unordered_map<string,int>dist;
        bool find=false;
        for(int i=0;i<wordList.size();i++)
        {
            if(wordList[i]==endWord)
            {
                find=true;
            }
        }
        bool found=false;
        for(int i=0;i<wordList.size();i++)
        {
            if(wordList[i]==endWord) found=true;

            if(check(beginWord,wordList[i]))
            {
                m[beginWord].push_back(wordList[i]);
                m[wordList[i]].push_back(beginWord);
            }

            for(int j=i+1;j<wordList.size();j++)
            {
                if(check(wordList[i],wordList[j]))
                {
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(!find) return 0;
        dist[beginWord]=1;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty())
        {
            string node=q.front();
            q.pop();
            if(node==endWord) return dist[node];
            for(int i=0;i<m[node].size();i++)
            {
                string neigh=m[node][i];
                if(!dist.count(neigh))
                {
                    dist[neigh]=dist[node]+1;
                    q.push(neigh);
                }
            }
        }
        return 0;
    }
};
