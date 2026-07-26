class Solution {
public:
    int paths(int row,int col,int m,int n, vector<vector<int>> &dp){
        //base case
        // agar last corner pe phoch gye toh return ek path mil gya;
        if(row==m-1 && col==n-1) return 1;
        if(row>=m || col>=n) return 0;//out bound case
        
        if(dp[row][col] !=-1) return dp[row][col];
        int down = paths(row+1,col,m,n,dp);
        int right = paths(row,col+1,m,n,dp);

        return dp[row][col] =  down+right;

    }


    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = paths(0,0,m,n,dp);
        return ans;
        
    }
};