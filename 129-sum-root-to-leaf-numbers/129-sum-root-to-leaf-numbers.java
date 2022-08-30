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
class Solution {
    int sum(TreeNode root,int currentNum)
    {
        if(root==null)
        {
            return 0;
        }
        currentNum=currentNum*10+root.val;
        if(root.left==null && root.right==null) return currentNum;
        int l=sum(root.left, currentNum);
        int r=sum(root.right,currentNum);
        return l+r;
    }
    public int sumNumbers(TreeNode root) {
        return sum(root,0);
        
    }
}