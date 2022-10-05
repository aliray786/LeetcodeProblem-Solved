  bool comparator(const string first,const string second)
	{
	    string one = first+second;
        string two = second+first;
    
    int i=0;
    while(one[i] && two[i])
    {
        if(one[i]>two[i])
            return true;
        else if(one[i]<two[i])
            return false;
        ++i;
    }
    
    return false;
	}
class Solution {
public:
   
    string largestNumber(vector<int>& nums) {
         int n=nums.size();
	   string ans="";
        vector<string>arr;
      for(int i=0;i<n;i++)arr.push_back(to_string(nums[i]));
	   sort(arr.begin(),arr.end(),comparator);
	   for(int i=0;i<n;i++)
	   {
	       ans+=arr[i];
	   }
       if(arr[0][0]=='0') return "0";
	   return ans;
        
    }
};