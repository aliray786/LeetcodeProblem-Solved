class MyCircularQueue {
     int [] arr; 
    int front=0,rear=-1, capacity,currentLen=0;

    public MyCircularQueue(int k) {
        arr=new int[k];
        capacity=k;
    }
    
    public boolean enQueue(int value) {
        if(!isFull())
        {
            rear=(rear+1)%capacity; 
            arr[rear]=value;
            rear=rear%capacity;
            currentLen++;
            return true;
    
        }
        return false;
        
    }
    
    public boolean deQueue() {
        if(!isEmpty())
        {
            front++;
            front=front%capacity;
            currentLen--;
            return true;
        }
        return false;
    }
    
    public int Front() {
        return isEmpty()?-1:arr[front];
        
    }
    
    public int Rear() {
        return isEmpty()?-1:arr[rear];
        
    }
    
    public boolean isEmpty(){
        return currentLen==0;
        
    }
    
    public boolean isFull() {
        return currentLen==capacity;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */