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
public:
    string ans="~";
    void solve(TreeNode* root,string currentStr)
    {
        if(root==NULL) return ;
        currentStr=char(root->val+'a')+currentStr;
        if(root->left==NULL and root->right==NULL) ans= min(currentStr,ans);
         solve(root->left,currentStr);
          solve(root->right,currentStr);
    }
    string smallestFromLeaf(TreeNode* root) {
         solve(root,"");
        return ans;
        
    };
};