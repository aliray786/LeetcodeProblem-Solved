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
    List<Integer>ans;
  
    public List<Integer> inorderTraversal(TreeNode root) {
        ans=new ArrayList<>();
        if(root==null) return ans;
        Stack<TreeNode>st=new Stack<>();
        while(root!=null || !st.isEmpty())
        {
            while(root!=null)
            {
                st.push(root);
                root=root.left;
            }
            root=st.peek();
            st.pop();
            ans.add(root.val);
            root=root.right;
            
        }
        return ans;
  
        
    }
}