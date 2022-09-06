class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int totRow=matrix.length;
        int totCol=matrix[0].length;
        int curRow=0,curCol=totCol-1;
        while(curRow<totRow && curCol>=0)
        {
            if(matrix[curRow][curCol]==target)
                return true;
           else if(matrix[curRow][curCol]>target)
            {
                curCol--;
            }
            else
            {
                curRow++;
            }
        }
        return false;
        
    }
}