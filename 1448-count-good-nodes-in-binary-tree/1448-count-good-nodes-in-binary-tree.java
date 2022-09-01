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
    int ans=0;
     void helper(TreeNode root,int mx)
    {
        if(root==null) return;
        if(root.val>=mx)
            ans++;
        mx=Math.max(mx,root.val);
        helper(root.left,mx);
        helper(root.right,mx);
    }
    public int goodNodes(TreeNode root) {
        helper(root,Integer.MIN_VALUE);
        return ans;
        
    }
}