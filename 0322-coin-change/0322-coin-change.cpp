class Solution {
public:
int n;
    int count(vector<int>& coins,int sum , int idx,vector<vector<int>>&dp){
        if(sum==0) return 0;
        if(idx==n) return INT_MAX-1;
        // if(sum<coins[idx]) return INT_MAX-1;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take = INT_MAX-1;
        if(sum>=coins[idx]){
           take =  1+count(coins,sum-coins[idx],idx,dp);
        }
        int not_take = count(coins,sum,idx+1,dp);
        return dp[idx][sum] =  min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = count(coins,amount,0,dp);
        if(ans==INT_MAX-1) return -1;
        else return ans;
    }
};