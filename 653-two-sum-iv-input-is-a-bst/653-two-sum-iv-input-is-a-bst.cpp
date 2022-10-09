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
    vector<int>inorder;
public:
    void inorderD(TreeNode* root)
    {
        if(root==NULL) return;
        inorderD(root->left);
        inorder.push_back(root->val);
        inorderD(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        inorderD(root);
        for(int i=0;i<inorder.size();i++)
        {
            if(mp.find(k-inorder[i])!=mp.end())
                return true;
            mp[inorder[i]]++;
        }
        return false;
        
    }
};