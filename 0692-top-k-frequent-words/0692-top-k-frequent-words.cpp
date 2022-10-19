#include<bits/stdc++.h>
class Solution {
public:
    struct comparator
    {
        bool operator()( pair<string, int>&a,  pair<string,int>&b){
          if(a.second!=b.second) return a.second>b.second;
               return a.first<b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto word:words)mp[word]++;
      // priority_queue<pair<string,int>,vector<pair<string,int>>,comparator>pq;  
                priority_queue<pair<string,int>, vector<pair<string,int>>,comparator>pq;
        for(auto i:mp)
        {
            pq.push({i.first,i.second});           
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<string>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};