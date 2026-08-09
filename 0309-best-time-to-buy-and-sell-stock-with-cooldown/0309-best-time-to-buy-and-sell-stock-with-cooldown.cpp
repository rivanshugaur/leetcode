class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                if(j==1){
                    int buy = -prices[i] + dp[i+1][false];
                    int not_buy = dp[i+1][true];
                    dp[i][j] = max(buy,not_buy);
                }
                else{
                    int sell = prices[i] + dp[i+2][true];
                    int not_sell = dp[i+1][false];
                    dp[i][j] = max(sell,not_sell);
                }
            }
        }
        return dp[0][1];
        /*
        returning dp[0][0] means assuming starting from day 0 and you already hold a stock which is wrong and

        return dp[0][1] means assuming starting from day 0 and you are not holding any stock and are ready to buy on day 0 itself which is correct 
        */
        
    }
};