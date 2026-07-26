class Solution {
public:
    int m;
    int n;
    int paths(int row,int col,vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        //base case
        // agar last corner pe phoch gye toh return ek path mil gya;
        if(row>=m || col>=n) return 0;//out bound case
        if(obstacleGrid[row][col]==1) return dp[row][col] = 0;
        if(row==m-1 && col==n-1) return 1;
        
        
        
        if(dp[row][col] !=-1) return dp[row][col];
        int down = paths(row+1,col,obstacleGrid,dp);
        int right = paths(row,col+1,obstacleGrid,dp);

        return dp[row][col] =  down+right;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans = paths(0,0,obstacleGrid,dp);
        return ans;
        
    }
};