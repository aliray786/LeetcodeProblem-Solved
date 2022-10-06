class TimeMap {
    
public:
    unordered_map<string,vector<pair<int,string>>>kv;
    TimeMap() {
       // kv.clear();
         ios_base::sync_with_stdio(false);
          cin.tie(NULL);
        
        
        
    }
    
    void set(string key, string value, int timestamp) {
        kv[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int ts) {
        if(kv.find(key)==kv.end())
            return "";
        else
        {
           int low=0, high=kv[key].size()-1;
           string ans="";
            if (ts < kv[key][0].first) {
            return "";
        }
           while(low<=high)
           {
               int mid=(low+high)/2;
               
               if(kv[key][mid].first==ts)
               {
                   return kv[key][mid].second;
               }
               else if(kv[key][mid].first>ts)
               {
                   high=mid-1;
               }
               else
               {
                   ans=kv[key][mid].second;
                   low=mid+1;
               }
           }
            return ans;
          
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */