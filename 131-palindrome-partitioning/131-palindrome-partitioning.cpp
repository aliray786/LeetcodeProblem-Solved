class Solution {
 vector<vector<string>>part;
public:
    bool isPalindrom(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void bfs(string s,int start,vector<string> &curS)
    {
        if(start>=s.length())
        {
            part.push_back(curS);
        }
        for(int end=start;end<s.length();end++)
        {
            if(isPalindrom(s,start,end))
            {
                curS.push_back(s.substr(start,end-start+1));
                bfs(s,end+1,curS);
                curS.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curs;
        bfs(s,0,curs);
        return part;
        
    }
};