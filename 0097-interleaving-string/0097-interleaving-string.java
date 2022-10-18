class Solution {
    int len1,len2,len3;
    public boolean isInterleave(String s1, String s2, String s3) {
        len1=s1.length();
        len2=s2.length();
        len3=s3.length();
                if(len1+len2!=len3) return false;

        boolean dp[][]=new boolean[len1+1][len2+1];
        int p3=0;
        for(int p1=0;p1<=len1;p1++)
        {
            for(int p2=0;p2<=len2;p2++)
            {
                p3=p1+p2-1;
                if(p1==0 && p2==0 )
                {
                    dp[p1][p2]=true;
                }
                else if(p1==0)
                {
                    dp[p1][p2]=s2.charAt(p2-1)==s3.charAt(p3) && dp[p1][p2-1];
                }
                else if(p2==0)
                {
                    dp[p1][p2]= s1.charAt(p1-1)==s3.charAt(p3) && dp[p1-1][p2];
                }
                else
                {
                    dp[p1][p2]=(s1.charAt(p1-1)==s3.charAt(p3) && dp[p1-1][p2] )|| (s2.charAt(p2-1)==s3.charAt(p3)&&dp[p1][p2-1]);
                }
            }
        }
        return dp[len1][len2];
    }
}