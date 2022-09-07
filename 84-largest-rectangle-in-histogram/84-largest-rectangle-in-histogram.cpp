class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        if(a.empty()) return 0;
          stack<pair<int ,int>> s;
    int n=a.size();
    vector<int>left;
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            left.push_back(-1);
        }
        else if(!s.empty() &&s.top().first<a[i])
        {
            left.push_back(s.top().second);
        }
        else if(!s.empty() &&s.top().first>=a[i])
        {
            while(!s.empty() &&s.top().first>=a[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                left.push_back(-1);
            }
            else
            {
                 left.push_back(s.top().second);

            }
        }
        s.push({a[i],i});
    }
    //stack<int>s;
    //s.clear();
    while(!s.empty())
    {
        s.pop();
    }
    vector<int>right;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        {
            right.push_back(n);
        }
        else if(!s.empty() &&s.top().first<a[i])
        {
            right.push_back(s.top().second);
        }
        else if(!s.empty() &&s.top().first>=a[i])
        {
            while(!s.empty() &&s.top().first>=a[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                right.push_back(n);
            }
            else
            {
                 right.push_back(s.top().second);

            }
        }
        s.push({a[i],i});
    }
    reverse(right.begin(),right.end());
    int w[n];
    for(int i=0;i<n;i++)
    {
        w[i]=right[i]-left[i]-1;
    }
    int ar[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ar[i]=a[i]*w[i];
        ans=max(ar[i],ans);
    }
        return ans;
        
    }
};