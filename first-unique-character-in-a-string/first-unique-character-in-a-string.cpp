class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freqOfChar(26,0);
        for(char ch:s)
            freqOfChar[ch-'a']++;
        for(int i=0;i<s.length();i++)
        {
            if(freqOfChar[s[i]-'a']==1)
                 return i;
        }
        return -1;

        
    }
};