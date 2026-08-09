class Solution {
public:

    int maxProfit(int j, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*j+1,0));
        
        for(int i = n-1;i>=0;i--){
            
                for(int k = 0;k<=2*j-1;k++){
                    if(k%2==0){
                        int buy = -prices[i] + dp[i+1][k+1];
                        int not_buy = dp[i+1][k];
                        dp[i][k] = max(buy,not_buy);
                    }
                    else{
                        int sell = prices[i] + dp[i+1][k+1];
                        int not_sell = dp[i+1][k];
                        dp[i][k] = max(sell,not_sell);
                    }
                }
            
        }
        return dp[0][0];


        
    }
};
