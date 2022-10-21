class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0;
        for(int num:nums)
        {
            if(mp.find(num)!=mp.end())
            {
                if(abs(mp[num]-i)<=k)
                    return true;
            }
            mp[num]=i;
            i++;
        }
        return false;
    }
};