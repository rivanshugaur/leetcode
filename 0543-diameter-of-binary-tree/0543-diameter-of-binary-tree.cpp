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
    int maxi = 0;
    int height(TreeNode* root){
        if(root==NULL) return -1;
        int lh = height(root->left)+1;
        int rh = height(root->right)+1;
        maxi = max({maxi,lh+rh,lh,rh});
        return max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->left && !root->right) return 0;

        int lh = 1+height(root->left);
        int rh = 1+height(root->right);

        return max({maxi,lh+rh}); 
        
    }
};