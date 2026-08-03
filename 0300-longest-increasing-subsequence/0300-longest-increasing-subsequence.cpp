class Solution {
public:
int dp[2501][2502]; //2502 beacause negative indexing is not allowed
int length(vector<int>& nums,int idx,int last_idx){
    //base case
    if(idx==nums.size()) return 0;

    //if(nums[idx]<last) return 0;
    if(dp[idx][last_idx+1]!=-1) return dp[idx][last_idx+1];
    
    int notTake = length(nums,idx+1,last_idx);
    int take = 0;
    if(last_idx==-1 || nums[idx]>nums[last_idx]){
        take = 1+length(nums,idx+1,idx);
    }

    return dp[idx][last_idx+1] = max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = length(nums,0,-1);
        return ans;
        
    }
};