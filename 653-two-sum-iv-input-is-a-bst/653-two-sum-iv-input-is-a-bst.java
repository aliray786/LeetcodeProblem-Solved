/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
   Stack<TreeNode>stack;
    boolean reverse=false;
    public BSTIterator(TreeNode root,boolean rev) {
        stack=new Stack<>();
        reverse=rev;
        pushAll(root);
    }
    void pushAll(TreeNode root)
    {
        while(root!=null && reverse==false)
        {
            stack.push(root);
            root=root.left;
        }
        while(reverse==true && root!=null)
        {
             stack.push(root);
            root=root.right;
        }
    }
    public int next() {
        TreeNode top=stack.pop();
        if(reverse)
        {
            pushAll(top.left);
        }
        else
        {
            pushAll(top.right);
        }
        return top.val;
        
    }
    
    public boolean hasNext() {
        return !stack.isEmpty();
        
    }
}
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        BSTIterator start=new BSTIterator(root,false);
        BSTIterator end=new BSTIterator(root,true);
        
        int i=start.next(),j=end.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j<k) i=start.next();
            else
            {
                j=end.next();
            }
        }
        return false;
        
    }
}