/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Queue<Node>q=new LinkedList<>();
        if(root==null) return null;
        q.add(root);
        while(!q.isEmpty())
        {
            
                int size=q.size();
                while(size>0)
                {
                       size--;
                     Node front=q.poll();
                front.next=size==0?null:q.peek();
                if(front.left!=null)
                    q.add(front.left);
                if(front.right!=null)
                    q.add(front.right);
                }
               
            
        }
        return root;
        
    }
}