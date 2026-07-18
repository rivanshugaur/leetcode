class Solution {
public:
vector<vector<int>>res;
    void solve(vector<int>&nums,vector<int>&ans,int idx){
        if(idx>nums.size()) return;
            res.push_back(ans);
        
        for(int i = idx;i<nums.size();i++){
            ans.push_back(nums[i]);
            solve(nums,ans,i+1);
            ans.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>ans;
        solve(nums,ans,0);
        return res;
    }
};