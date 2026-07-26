class Solution {
public:
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {
        
        if (row == triangle.size()-1) return triangle[row][col];

        
        if (dp[row][col] != INT_MAX) return dp[row][col];

       
        int path1 = triangle[row][col] + solve(triangle, row + 1, col, dp);
        int path2 = triangle[row][col] + solve(triangle, row + 1, col + 1, dp);

        return dp[row][col] = min(path1, path2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return solve(triangle, 0, 0, dp);
    }
};