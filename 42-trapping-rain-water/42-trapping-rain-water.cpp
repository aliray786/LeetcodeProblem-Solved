class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
     vector< int >maxl(n);
      vector< int > maxr(n);
        int ans=0;
        if(n==0) return 0;
        maxl[0]=height[0];
        maxr[n-1]=height[n-1];
         for(int j=1;j<n;j++)
            {
                maxl[j]=max(maxl[j-1],height[j]);
            }
         for(int j=n-2;j>=0;j--)
            {
                maxr[j]=max(maxr[j+1],height[j]);
            }
        for(int i=0;i<n;i++)
        {
            ans+=min(maxl[i],maxr[i])-height[i];
        }
       
        return ans;
    }
};