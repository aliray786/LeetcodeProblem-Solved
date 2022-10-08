class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n=a.size();
        vector<vector<int> > res;
        if(n<3) return res;
        
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
        
            int l=i+1;
            int h=n-1;
            int target=-a[i];
            if(target<0) break;
            while(l<h)
            {
                int sum=a[l]+a[h];
                if(sum>target)
                {
                    h--;
                }
                else if(sum<target)
                {
                    l++;
                }
                else
                {
                    vector<int>triplet(3,0);
                   triplet[0] = a[i];
                   triplet[1] = a[l];
                   triplet[2] = a[h];
                    res.push_back(triplet);
                 
                    while(l<h && a[l]==triplet[1]) l++;
                    while(l<h && a[h]==triplet[2]) h--;
                }
            }
                while (i + 1 < a.size() && a[i + 1] == a[i]) i++;
                         
        }
        return res;
        
        
    }
};