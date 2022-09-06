class Solution {
public:
    string reformat(string s) {
        string a,d;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]-'a'<26 && s[i]-'a'>=0)
            {
                a.push_back(s[i]);
            }
            else
            {
                d.push_back(s[i]);
            }
        }
        if(abs((int)a.length()-(int)d.length())>1) return "";
        
        bool push=a.length()>=d.length();
        int i=0,j=0,k=0;
        while(i<s.length())
           {
               if(push)
               {
                   s[i++]=a[j++];
               }
               else
                   s[i++]=d[k++];
               push=!push;
           }
           return s;
           
           
      
    }
};