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
    private :
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev=NULL;
public:
    void recoverTreeH(TreeNode* root)
    {
        if(root==NULL) return ;
        recoverTreeH(root->left);
        if(prev!=NULL and prev->val>root->val)
        {
          if(first==NULL)
          {
              first=prev;
          }
              second=root;
        }
        prev=root;
        recoverTreeH(root->right);
    }
    void recoverTree(TreeNode* root) {
        recoverTreeH(root);
        int t=first->val;
        first->val=second->val;
        second->val=t;
        
    }
};