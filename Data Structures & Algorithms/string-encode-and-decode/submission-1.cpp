class Solution {
public:
bool check(string s,int index)
{
    string ans=s.substr(index,4);
    return ans=="asad";
}
    string encode(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs.size();i++)
        {
            ans+=strs[i];
            ans+="asad";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        string temp="";
        while(i<s.length())
        {
            while(i<s.length() && !check(s,i))
            {
                temp+=s[i];
                i+=1;
            }
            ans.push_back(temp);
            temp="";
            i+=4;
        }
        return ans;
    }
};
