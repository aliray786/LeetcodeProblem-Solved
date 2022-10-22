class Solution {
public:
    string minWindow(string s, string t) {
        int n=t.size();
        int count;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
            mp[t[i]]++;
        count=mp.size();
        int minleft,minlen=INT_MAX;
        int l,r;l=0;
         n=s.size();
        for(r=0;r<n;r++)
        {
            if(mp.find(s[r])!=mp.end())
            {
                mp[s[r]]--;
                if(mp[s[r]]==0)
                {
                    count--;
                }
            }
            while(count==0)
            {
                if(minlen>r-l+1)
                {
                    minlen=r-l+1;
                    minleft=l;
                }
                if(mp.find(s[l])!=mp.end())
                {
                    mp[s[l]]++;
                    if(mp[s[l]]>0)count++;
                }
                l++;
            }
        }
        if(minlen>n ) return "";
        return s.substr(minleft,minlen);
            
        
    }
};