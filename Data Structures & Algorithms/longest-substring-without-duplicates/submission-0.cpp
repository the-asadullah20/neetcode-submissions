class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int j=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]+=1;
            while(m[s[i]]>1)
            {
                m[s[j]]--;
                j++;
            }
             maxi=max(maxi,i-j+1);
        }
        return maxi;
    }
};
