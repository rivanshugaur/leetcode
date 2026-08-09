class Solution {
public:

    int solve(vector<int>& prices,int idx,int flag, vector<vector<int>> &dp){
        //base case
        if(idx>=prices.size()) return 0;

        if(dp[idx][flag]!=-1) return dp[idx][flag];

        if(flag){
            int buy = -prices[idx] + solve(prices,idx+1,false,dp);
            int not_buy = solve(prices,idx+1,true,dp);

            return dp[idx][flag] =  max(buy,not_buy);

        }
        else{
            int sell = prices[idx] + solve(prices,idx+2,true,dp);
            int not_sell = solve(prices,idx+1,false,dp);

            return dp[idx][flag] = max(sell,not_sell);

        }
        return 0;

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = solve(prices,0,true,dp);
        return ans;
        
    }
};