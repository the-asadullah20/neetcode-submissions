
class Solution {
public:
vector<string>temp;
vector<vector<string>>ans;
bool is(string s,int l,int r)
{
    while(l<r)
    {
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return 1;
}

void solve(string s,int start)
{
    if(start==s.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i=start;i<s.size();i++)
    {
        if(is(s,start,i))
        {
            temp.push_back(s.substr(start,i-start+1));
            solve(s,i+1);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};
