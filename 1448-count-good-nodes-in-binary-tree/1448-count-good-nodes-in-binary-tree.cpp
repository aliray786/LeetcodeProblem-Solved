/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans=0;
public:
    void helper(TreeNode* root,int mx)
    {
        if(root==NULL) return;
        if(root->val>=mx)
            ans++;
        mx=max(mx,root->val);
        helper(root->left,mx);
        helper(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        ans=0;
        helper(root,INT_MIN);
        return ans;
        
    }
};