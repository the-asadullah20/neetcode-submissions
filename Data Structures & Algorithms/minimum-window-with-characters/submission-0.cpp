class Solution {
public:
bool check(vector<int>&a,vector<int>&b)
{
    for(int i=0;i<128;i++)
    {
        if(a[i]<b[i])
        {
            return false;
        }
    }
    return true;
}
    string minWindow(string s, string t) {
        if(!t.length() || t.length()>s.length()) return "";
        vector<int>a(128,0);
        vector<int>b(128,0);
        int mini=INT_MAX;
        for(int i=0;i<t.length();i++)
        {
            b[t[i]]++;
        }
        int j=0;
        int ans=0;
        int index=-1;
        for(int i=0;i<s.length();i++)
        {
            a[s[i]]++;
            while(check(a,b))
            {
                if(mini>i-j+1)
                {
                    mini=i-j+1;
                    index=j;
                }
                a[s[j]]--;
                j++;
            }
        }
        if(index==-1) return "";
        return s.substr(index,mini);
    }
};
