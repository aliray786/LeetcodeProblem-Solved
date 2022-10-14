class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
      vector<int>givenCharPos;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c)
            {
                givenCharPos.push_back(i);
            }
        }
        vector<int>ans(s.size(),INT_MAX);
        for(int i=0;i<s.size();i++)
        {
            for(int val:givenCharPos)
            {
                cout<<val<<" ";
                ans[i]=min(ans[i],abs(i-val));
            }
        }
        return ans;
    }
};