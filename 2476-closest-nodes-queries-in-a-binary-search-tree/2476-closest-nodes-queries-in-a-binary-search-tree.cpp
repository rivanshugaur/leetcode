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
vector<int>res;
    void inorder(TreeNode* root){
        if(root==NULL) return;

        TreeNode* temp = root;
        stack<TreeNode*>st;
        while(!st.empty() || temp){
            while(temp){
                st.push(temp);
                temp = temp->left;

            }
            temp = st.top();
            st.pop();
            res.push_back(temp->val);
            temp = temp->right;
            
        }

    }


    void solve(int& maxi, int& mini,int target){
        int i = 0;
        int j = res.size()-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(res[mid]==target){
                mini = res[mid];
                maxi = res[mid];
                return;
            }
            if(res[mid]<target){
                mini = res[mid];
                i = mid+1;
            }
            else{
                maxi = res[mid];
                j = mid-1;
            }
        }

    }
   

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        inorder(root);
        // for(auto ele: res){
        //     cout<<ele<<" ";
        // }
        int len = res.size();
        vector<vector<int>> ans(n);
        for(int i = 0;i<n;i++){
            int target = queries[i];
            int mini = -1;
            int maxi = -1;
            solve(maxi,mini,target);
            ans[i] = {mini,maxi};

        }
        
        return ans;
    }
};