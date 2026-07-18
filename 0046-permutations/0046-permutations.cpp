class Solution {
public:
vector<vector<int>>res;
int n;
    void solve(vector<int>& nums,vector<int>& ans,vector<bool>&visited){
        if(ans.size()==nums.size()){
            res.push_back(ans);
            return;
        }

        for(int i = 0;i<n;i++){
            if(visited[i]) continue;
            ans.push_back(nums[i]);
            visited[i] = true;
            //explore one 
            solve(nums,ans,visited);
            visited[i] = false;
            ans.pop_back();

        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int>ans;
        vector<bool>visited(n);
        solve(nums,ans,visited);
        return res;
        
    }
};