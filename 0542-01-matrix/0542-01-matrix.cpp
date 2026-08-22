class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));

        queue<pair<int,int>> qt;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0){
                    qt.push({i,j});
                    ans[i][j] = 0;

                } 

            }
        }
        while(!qt.empty()){
            pair tp = qt.front();
            qt.pop();

            int i = tp.first;
            int j = tp.second;
            //top
            if(i-1>=0 && ans[i-1][j]==-1){
                qt.push({i-1,j});
                ans[i-1][j] = ans[i][j]+1;
            }
            //left
            if(j-1>=0 && ans[i][j-1]==-1){
                qt.push({i,j-1});
                ans[i][j-1] = ans[i][j]+1;
            }
            //right
            if(j+1<m && ans[i][j+1]==-1){
                qt.push({i,j+1});
                ans[i][j+1] = ans[i][j]+1;
            }
            //down
            if(i+1<n && ans[i+1][j]==-1){
                qt.push({i+1,j});
                ans[i+1][j] = ans[i][j]+1;
            }



        }
        return ans;
        
    }
};