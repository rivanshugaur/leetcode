class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rl = 0;
        int rh = matrix.size()-1;
        int cl = 0;
        int ch = matrix[0].size()-1;
        int i = 0;
        vector<int>ans;
        while(rl<=rh && cl<=ch){
            i = cl;
            while(i<=ch){
                ans.push_back(matrix[rl][i]);
                i++;
            }
            rl++;
            i = rl;
            while(i<=rh){
                ans.push_back(matrix[i][ch]);
                i++;

            }
            ch--;

            
            if(rl<=rh){
                i = ch;
                while(i>=cl){
                ans.push_back(matrix[rh][i]);
                i--;
            }

            }
            
            rh--;
            
            if(cl<=ch){
                i = rh;
                while(i>=rl){
                ans.push_back(matrix[i][cl]);
                i--;
            }

            }
            
            cl++;
        }
        return ans;
        
        
    }
};