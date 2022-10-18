class Solution {
    int len1,len2,len3;
    String s1,s2,s3;
    Map<String,Boolean>mp=new HashMap<>();
    boolean isPos(int p1,int p2,int p3)
    {
        if(p3==len3)
        {
            return p1==len1 && p2==len2;
        }
        String key=p1+"*"+p2+"*"+p3;
        if(mp.containsKey(key))
            return mp.get(key);
       else if(p1==len1)
        {
            return s2.charAt(p2)==s3.charAt(p3)?isPos(p1,p2+1,p3+1):false;
        }
        else if(p2==len2)
        {
            return s1.charAt(p1)==s3.charAt(p3)?isPos(p1+1,p2,p3+1):false;
        }
        boolean first=false,second=false;
        if(s1.charAt(p1)==s3.charAt(p3))
        {
            first=isPos(p1+1,p2,p3+1);
        }
        if(s2.charAt(p2)==s3.charAt(p3))
        {
            second=isPos(p1,p2+1,p3+1);
        }
        mp.put(key,(first ||second));
        return first || second;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        len1=s1.length();
        len2=s2.length();
        len3=s3.length();
        this.s1=s1;this.s3=s3;this.s2=s2;
        if(len1+len2!=len3) return false;
        return isPos(0,0,0);
    }
}