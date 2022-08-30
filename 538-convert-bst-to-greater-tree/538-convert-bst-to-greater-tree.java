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
    int curSum=0;
    void convert(TreeNode root)
    {
        if(root==null) return ;
        convert(root.right);
        root.val=root.val+curSum;
        curSum=root.val;
        convert(root.left);
        
    }
    public TreeNode convertBST(TreeNode root) {
        convert(root);
        return root;
        
    }
}