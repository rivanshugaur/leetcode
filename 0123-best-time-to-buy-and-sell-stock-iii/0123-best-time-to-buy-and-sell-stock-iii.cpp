class Solution {
public:

    // int solve(vector<int>& prices, int idx,int flag,int cap, vector<vector<vector<int>>> &dp){
    //     //base case
    //     if(cap==0 || idx==prices.size()) return 0;

    //     if(dp[idx][flag][cap]!=-1) return dp[idx][flag][cap];

    //     if(flag){
    //         int sell = prices[idx] + solve(prices,idx,false,cap-1,dp);
    //         int not_sell = solve(prices,idx+1,true,cap,dp);

    //         return dp[idx][flag][cap] = max(sell,not_sell);
    //     }
    //     else{
    //         int buy = -prices[idx] + solve(prices,idx+1,true,cap,dp);
    //         int not_buy = solve(prices,idx+1,false,cap,dp);

    //         return dp[idx][flag][cap] = max(buy,not_buy);
    //     }
    //     return 0;
    // }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                for(int k = 1;k<=2;k++){
                    if(j==0){
                        int buy = -prices[i] + dp[i+1][1][k];
                        int not_buy = dp[i+1][0][k];
                        dp[i][j][k] = max(buy,not_buy);
                    }
                    else{
                        int sell = prices[i] + dp[i][0][k-1];
                        int not_sell = dp[i+1][1][k];
                        dp[i][j][k] = max(sell,not_sell);
                    }
                }
            }
        }
        return dp[0][0][2];

    }
};