class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = -1;
        int fresh = 0;

        queue<pair<int,int>>qt;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==2) qt.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }

        }
        if(fresh==0) return 0;
        while(!qt.empty()){
            count++;
            int len = qt.size();
            for(int it = 0;it<len;it++){
                pair tp = qt.front();
                qt.pop();
                int i = tp.first;
                int j = tp.second;
                //grid[i][j]=2;
                if(i-1>=0 && grid[i-1][j]==1){
                    qt.push({i-1,j});
                    grid[i-1][j] = 2;
                    fresh--;
                }
                if(j-1>=0 && grid[i][j-1]==1){

                    qt.push({i,j-1});
                    grid[i][j-1] = 2;
                    fresh--;
                }
                if(j+1<m && grid[i][j+1]==1){

                    qt.push({i,j+1});
                    grid[i][j+1] = 2;
                    fresh--;
                }
                if(i+1<n && grid[i+1][j]==1){

                    qt.push({i+1,j});
                    grid[i+1][j] = 2;
                    fresh--;
                }
            } 
        }
       
        return fresh==0 ? count : -1;
        
    }
};