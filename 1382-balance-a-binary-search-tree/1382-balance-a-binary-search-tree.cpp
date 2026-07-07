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
vector<TreeNode*> res;
    void inorder(TreeNode* root){
        if(root==NULL) return;

        stack<TreeNode*>st;
        TreeNode* temp = root;
        while(!st.empty() || temp!=NULL){
            while(temp){
                st.push(temp);
                temp = temp->left;
            }
            temp =st.top();
            st.pop();
            res.push_back(temp);
            temp = temp->right;
        }
    }

    TreeNode* construct(int left , int right){
        int n = res.size();
        if(n==1) return res[0];
        if(left>right) return NULL;

        int mid = left+(right-left)/2;
        TreeNode* root = res[mid];
        root->left = construct(left,mid-1);
        root->right = construct(mid+1,right);

        return root;

    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = res.size();
        TreeNode* node = construct(0,n-1);
        return node;
        
    }
};