class Solution {
    public class Cell implements Comparable<Cell>
    {
        int row;
        int col;
        int height;
        Cell(int r,int c,int h)
        {
            this.row=r;
            this.col=c;
            this.height=h;
        }
        @Override
        public int compareTo(Cell c)
        {
            return this.height-c.height;
        }
        
    }
    public int trapRainWater(int[][] height) {
        int totRow=height.length;
        int totCol=height[0].length;
        if(height==null || totRow<=2 || totCol<=2) return 0;
        PriorityQueue<Cell>pq=new PriorityQueue<Cell>();
        boolean[][]vis=new boolean[totRow][totCol];
      for (int i = 0; i < totRow; i++) {
	            vis[i][0] = true;
	            vis[i][totCol - 1] = true;
	            pq.offer(new Cell(i, 0, height[i][0]));
	            pq.offer(new Cell(i, totCol - 1, height[i][totCol - 1]));
	        }

	        for (int i = 0; i < totCol; i++) {
	            vis[0][i] = true;
	            vis[totRow - 1][i] = true;
	            pq.offer(new Cell(0, i, height[0][i]));
	            pq.offer(new Cell(totRow - 1, i, height[totRow - 1][i]));
	        }
        int water=0;
        int[][]dirs=new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!pq.isEmpty())
        {
            Cell prCell=pq.poll(); 
            for(int[]dir:dirs)
            {
                int row=prCell.row+dir[0];
                int col=prCell.col+dir[1];
                if(row>=0 && col>=0 && col<totCol && row<totRow
                  && !vis[row][col])
                {
                  
                    water+=Math.max(0,prCell.height-height[row][col]);                 
                    pq.offer(new Cell(row,col,Math.max(height[row][col],prCell.height)));
                    vis[row][col]=true;
                    
                }
            }
        }
        return water;
        
        
    }
}