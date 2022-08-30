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
    public TreeNode convertBST(TreeNode root) {
        Stack<TreeNode>st=new Stack<>();
        int sum=0;
        TreeNode r=root;
        while(root!=null || !st.isEmpty())
        {
            if(root!=null)
            {
               st.push(root);
               root=root.right;
                
            }
            else
            {
                root=st.peek();
                st.pop();
                root.val=root.val+sum;
                sum=root.val;
                root=root.left;
            }
        }
        return r;
        
    }
}