class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n+1,0);
        ans[0] = 0; 
        ans[1] = nums[0];
        for(int i = 2;i<=n;i++){
            ans[i] = max((nums[i-1]+ans[i-2]) , ans[i-1]);
        }
        return ans[n];
    }
};