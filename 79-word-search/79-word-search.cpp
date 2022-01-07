class Solution {
public:
    bool isExists(vector<vector<char>>& board, string word,int row,int col,int currentPos)
    {
        if(currentPos==word.size())
        {
            return true;
        }
        if(row<0 or col <0 or row>=board.size() or col>=board[0].size())       return false;
        if(board[row][col]!=word[currentPos])            return false;
        board[row][col]='*';
        bool isExist=(isExists(board,word,row+1,col,currentPos+1) or isExists(board,word,row-1,col,currentPos+1) or isExists(board,word,row,col-1,currentPos+1)
            or isExists(board,word,row,col+1,currentPos+1));
        board[row][col]=word[currentPos];
        return isExist;
    
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
            {
                if(isExists(board,word,i,j,0))
                    return true;
            }
        
        return false;
        
    }
};
