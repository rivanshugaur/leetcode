class Solution {
public:
int dp[101];
    int houserob(vector<int>& nums,int start,int end){
        if(start>=end) return 0;

        if(dp[start]!=-1) return dp[start];

        int robhim = nums[start] + houserob(nums,start+2,end);
        int notrob = houserob(nums,start+1,end);

        return dp[start] =  max(robhim,notrob);
    }
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        int lh = houserob(nums,0,n-1);
        memset(dp,-1,sizeof(dp));
        int rh = houserob(nums,1,n);

        return max(lh,rh);


        
    }
};