class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        /*
        tune sare kar liye 
        bhai hame bhi python mai karne padenge kuch swal
        manle allowed nhi hui toh 
        syntax ki vajah se easy question bhi nhi kar payenge
        abe python toh har jagah allowed dikhi hai jha bhi humne test diye along with cppp
        are cpp mostly log karte hai cp ke liye jyadatar content cpp mia hee hota hai
        bhai iss bkl ne apni video mai bola hai ki nhi allowed hota hai 
        toh usne bola nhi ki kabhi allowed karte hai kabhi nhi
        nayi off campus opening aayi hai 
        */
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> qt;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 || j==0 || j==m-1 || i==n-1 ){
                    if(grid[i][j]==1) qt.push({i,j});
                    grid[i][j] = -1;
                }
            }
        }

        while(!qt.empty()){
            pair top = qt.front();
            qt.pop();
            int i = top.first;
            int j = top.second;

             //top
            if(i-1>=0 && grid[i-1][j]==1){
                qt.push({i-1,j});
                grid[i-1][j] = -1;
            }
            //left
            if(j-1>=0 && grid[i][j-1]==1){
                qt.push({i,j-1});
                grid[i][j-1] = -1;
            }
            //right
            if(j+1<m && grid[i][j+1]==1){
                qt.push({i,j+1});
                grid[i][j+1] = -1;
            }
            //down
            if(i+1<n && grid[i+1][j]==1){
                qt.push({i+1,j});
                grid[i+1][j] = -1;
            }
        }

        int count = 0;

          for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;

        
    }
};