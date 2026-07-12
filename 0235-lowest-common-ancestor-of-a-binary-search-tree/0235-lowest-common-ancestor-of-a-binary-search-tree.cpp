/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==NULL || root==p || root == q ) return root;

        TreeNode* lh = lca(root->left,p,q);
        TreeNode* rh = lca(root->right,p,q);

        if(lh==NULL && rh==NULL) return NULL;
        else if(lh==NULL) return rh;
        else if(rh == NULL) return lh;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        return lca(root,p,q);
    }
};