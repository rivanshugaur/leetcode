class Solution {
public:
    // int solve(string& s1 , string& s2, int i , int j ,  vector<vector<int>>&dp){
    //     //base case
    //     if(i==s1.size()) return s2.size() - j;
    //     if(j==s2.size()) return s1.size() - i;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     if(s1[i]==s2[j]) return dp[i][j] =  0 + solve(s1,s2,i+1,j+1,dp);

    //     int delet_s1 = solve(s1,s2,i+1,j,dp);
    //     int delet_s2 = solve(s1,s2,i,j+1,dp);

    //     return dp[i][j] =  1 + min(delet_s1,delet_s2);
    // }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        // int ans = solve(word1,word2,0,0,dp);
        // return ans;

        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j] = i+j;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j] , dp[i][j-1]});
                }
                
            }
        }
        return dp[n][m];
        
    }
};