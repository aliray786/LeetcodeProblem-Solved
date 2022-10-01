class Solution {
public:
  /*  bool isvalid(string s)
    {
        if(s.length()==0 || s[0]=='0' ) return false;
        int val=stoi(s);
        return val<=26 && val>=1;
    }
    int solve(string s,int dpoint, vector<int> &mem)
    {
        if(dpoint>=s.length()) return 1;
        if(mem[dpoint]>-1) return mem[dpoint];
        int total=0;
        for(int i=1;i<=2;i++)
        {
            if(dpoint+i<=s.length()){
                 string Break=s.substr(dpoint,i);
            if(isvalid(Break))
            {
                total+=solve(s,dpoint+i,mem);
            }
            }
        }
        mem[dpoint]=total;
        return total;
    }*/
    
    int numDecodings(string s) {
       /*vector<int>mem(s.length()+1,-1);
        return solve(s,0,mem);*/
        int n=s.length();
        int first=1;
        int second=s[0]=='0'?0:1;
        for(int i=2;i<=n;i++)
        {
            int ans=0;
            int one=stoi(s.substr(i-1,1));
            int two=stoi(s.substr(i-2,2));
            if(one>=1)
            {
                ans+=second;
            }
            if(two>=10 && two<=26)
            {
                ans+=first;
            }
            first=second;
            second=ans;
                
        }
        return second;
    }
};