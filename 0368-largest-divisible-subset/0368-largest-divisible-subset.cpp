class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {nums[0]};
        vector<int>idx(n,-1);
        vector<int>dp(n,1);
        vector<int>ans;
        int max_len = 0;
        int max_idx = 0;
        sort(nums.begin(),nums.end());
        int prev = -1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){//dp[i]<dp[j]+1 is important to find the largest subset without it,it will lead to ans smaller ans check for 2,4,3,12 wihtout dp condition 3,12 and with dp 2,4,12
                    dp[i] = dp[j]+1;
                    idx[i] = j;
                }
            }
            if(dp[i]>max_len){
                max_len = dp[i];
                max_idx = i;
            }
        }

       while(max_idx!=-1){
        ans.push_back(nums[max_idx]);
        max_idx = idx[max_idx];
       }
       // if(idx == -1) return ans;
        // for(auto ele : idx){
        //     cout<<ele<<" ";
        // }
        return ans;
        
    }
};