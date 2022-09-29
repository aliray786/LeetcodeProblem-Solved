bool compare(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        for(int i=0;i<startTime.size();i++)
        {
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end(),compare);
        int size=jobs.size();
        vector<int>dp(size);
        dp[0]=jobs[0][2];
        for(int i=1;i<size;i++)
        {
            int firstNonOverlappingProfit=0;
            for(int j=i-1;j>=0;j--)
            {
                if(jobs[j][1]<=jobs[i][0])
                {
                     firstNonOverlappingProfit=dp[j];
                     break;
                }
            }
            
           dp[i]=max(dp[i-1],firstNonOverlappingProfit+jobs[i][2]);
            
        }
        return dp[size-1];
    }
};