class TrieNode{
    public:
    TrieNode * child[26];
    bool eow;
    TrieNode()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=nullptr;
        }
        eow=false;
    }
};

class Trie{
    public:
    TrieNode * root;
    Trie()
    {
        root= new TrieNode();
    }
    void insert(string s)
    {
        TrieNode *curr= root;
        for(int i=0;i<s.length();i++)
        {
            if(curr->child[s[i]-'a']==nullptr)
            {
                curr->child[s[i]-'a']= new TrieNode();
            }
            curr=curr->child[s[i]-'a'];
        }
        curr->eow=true;
    }
    bool startswith(string s)
    {
        TrieNode *curr= root;
        for(int i=0;i<s.length();i++)
        {
            if(curr->child[s[i]-'a']==nullptr) return false;
            curr=curr->child[s[i]-'a'];
        }
        return true;
    }
    bool search(string s)
    {
        TrieNode *curr= root;
        for(int i=0;i<s.length();i++)
        {
            if(curr->child[s[i]-'a']==nullptr) return false;
            curr=curr->child[s[i]-'a'];
        }
        return curr->eow;
    }
};
void dfs(int i,int j,string &ans,Trie &t,vector<vector<char>>&board,vector<string>&hehe,vector<vector<bool>>&visited)
{
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
    if(visited[i][j]) return;
    ans+=board[i][j];

    visited[i][j]=true;
    if(!t.startswith(ans))
    {
        ans.pop_back();
        visited[i][j]=false;
        return;
    }
    if(t.search(ans) && (find(hehe.begin(),hehe.end(),ans)==hehe.end()))
    {
        hehe.push_back(ans);
    }
    dfs(i+1,j,ans,t,board,hehe,visited);
    dfs(i-1,j,ans,t,board,hehe,visited);
    dfs(i,j+1,ans,t,board,hehe,visited);
    dfs(i,j-1,ans,t,board,hehe,visited);
    ans.pop_back();
    visited[i][j]=false;

}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        Trie t;
        for(int i=0;i<words.size();i++)
        {
            t.insert(words[i]);
        }

        for(int i=0;i<board.size();i++)
        {
            string s="";
            for(int j=0;j<board[0].size();j++)
            {
                dfs(i,j,s,t,board,ans,visited);
            }
        }
        return ans;
    }
};