class Solution {
public:
    int helper(string s,int k,char ch)
{
    int maxLen=1,changedChar=0;
    int n=s.length();
    int start=0,end=0;
    for(end=0;end<n;end++)
    {
        if(s[end]!=ch)
        {
            changedChar++;
        }
        while(changedChar>k)
        {
            if(s[start]!=ch)
            {
                changedChar--;
            }
            start++;
        }
        maxLen=max(maxLen,end-start+1);
    }
    return maxLen;
}

    int characterReplacement(string s, int k) {
         int ans=1;
    for(int i=0;i<26;i++)
    {
        ans=max(ans,helper(s,k,'A'+i));
    }
    return ans;
    }
};