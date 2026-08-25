class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
        matlab connect ed ko # kar do aur baad mai # ko o kar do aur o ko x aur x ko x rehnbe do 
        iss moti ko lead mai bhi aavaj aari kya hamari 
        apne kaam pe kam dhyan ham kya bolre uspe jyada dhyan deri bkl
        bhai mai toh c ka syntax bhool sa gya hu 
        
        */
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>qt;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 || j==0 || j==m-1 || i==n-1){
                    if(board[i][j]=='O'){
                        board[i][j] = '#';
                        qt.push({i,j});

                    } 

                }
            }
        }
        while(!qt.empty()){
            pair top = qt.front();
            qt.pop();
            int i = top.first;
            int j = top.second;
            

             //top
            if(i-1>=0 && board[i-1][j]=='O'){
                qt.push({i-1,j});
                board[i-1][j] = '#';
            }
            //left
            if(j-1>=0 && board[i][j-1]=='O'){
                qt.push({i,j-1});
                board[i][j-1] = '#';
            }
            //right
            if(j+1<m && board[i][j+1]=='O'){
                qt.push({i,j+1});
                board[i][j+1] = '#';
            }
            //down
            if(i+1<n && board[i+1][j]=='O'){
                qt.push({i+1,j});
                board[i+1][j] = '#';
            }
        }

         for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == 'O') board[i][j] = 'X'; 
                if(board[i][j] == '#') board[i][j] = 'O'; 
                //if(board[i][j] == 'o') board[i][j] = 'x'; 
            }
        }
        


        
    }
};