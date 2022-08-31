class Solution {
    vector<vector<bool>>pacific,atlantic;
    int row,col;
    vector<vector<int>>ans;
    
public:
    void dfs(vector<vector<int>>& heights,vector<vector<bool> >& visited,int i ,int j)
    {
        
        if(visited[i][j])
            return ;
        visited[i][j]=true;
        if(pacific[i][j] and atlantic[i][j])
            ans.push_back({i,j});
        if(i+1<row and heights[i+1][j]>=heights[i][j])
        {
            dfs(heights,visited,i+1,j);
        }
        if(j+1<col and heights[i][j+1]>=heights[i][j])
        {
            dfs(heights,visited,i,j+1);
        }
        if(i-1>=0 and heights[i-1][j]>=heights[i][j])
        {
            dfs(heights,visited,i-1,j);
        }
        if(j-1>=0 and heights[i][j-1]>=heights[i][j])
        {
            dfs(heights,visited,i,j-1);
        }
        return ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row=heights.size(),col=heights[0].size();
        pacific=atlantic=vector<vector<bool> >(row, vector<bool>(col, false));
        
        for(int j=0;j<col;j++)
        {
            dfs(heights,pacific,0,j);
            dfs(heights,atlantic ,row-1,j);
        }
         for(int i=0;i<row;i++)
        {
            dfs(heights,pacific,i,0);
            dfs(heights,atlantic ,i,col-1);
        }
        return ans;
        
        
        
    }
};