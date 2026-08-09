class Solution {
public:

     int solve(vector<int>& prices, int idx,int flag,int cap, vector<vector<vector<int>>> &dp){
        //base case
        if(cap==0 || idx==prices.size()) return 0;

        if(dp[idx][flag][cap]!=-1) return dp[idx][flag][cap];

        if(flag){
            int sell = prices[idx] + solve(prices,idx,false,cap-1,dp);
            int not_sell = solve(prices,idx+1,true,cap,dp);

            return dp[idx][flag][cap] = max(sell,not_sell);
        }
        else{
            int buy = -prices[idx] + solve(prices,idx+1,true,cap,dp);
            int not_buy = solve(prices,idx+1,false,cap,dp);

            return dp[idx][flag][cap] = max(buy,not_buy);
        }
        return 0;
    }


    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        int ans = solve(prices,0,false,k,dp);
        return ans;
        
    }
};
