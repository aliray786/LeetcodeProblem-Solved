class Solution {
    public int maxProfit(int[] inventory, int orders) {
        
        PriorityQueue<Ball> pq = new PriorityQueue<>((a, b) -> Long.compare(b.value, a.value));
        for (int value : inventory) {
            pq.offer(new Ball(value, 1));
        }
        
        long profit = 0;
        
        while (orders > 0 && !pq.isEmpty()) {
            
            Ball top = pq.poll();
            
            // Merge the count of balls that have the same value 
            while (!pq.isEmpty() && pq.peek().value == top.value) {
                top.count += pq.poll().count;
            }
            
            // Compare the ball with the greatest value to the next ball with greatest value
            long diff = pq.isEmpty() ? top.value : top.value - pq.peek().value;
            
            // See if we can fit all balls from current value to next value
            if (top.count * diff <= orders) {
                orders -= top.count * diff;
                profit += top.count * sumFromAToB(top.value, top.value - diff);
                
                // Add reduced value back into the pq
                if (top.value - diff > 0) {
                    pq.offer(new Ball(top.value - diff, top.count));
                }    
            } else {
                // We can only fit some of the balls from current value to next value. 
                // Figure out how many of the balls with the highest value will fit
                int len = orders / top.count;
                
                // Add profit for each ball that we can fit at the highest value
                profit += top.count * sumFromAToB(top.value, top.value - len);
                
                // Add profit for each ball that we cannot fit at the highest value
                profit += (orders % top.count) * (top.value - len);
                orders = 0;
            }
        }
        return (int) (profit % 1000000007);
    }
    
    private long sumFromAToB(long a, long b){
        return (a * (a+1))/2 - (b * (b+1))/2;
    }
    
    private class Ball {
        long value;
        int count;

        Ball(long value, int count) {
            this.value = value;
            this.count = count;
        }
    }
    
}