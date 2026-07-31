class Solution {
public:

int dp[2001][2001];

    bool solve(string &s, string &p, int i,int j){
        //base case
        //both are exhausted
        if(i==s.size() && j==p.size()) return true;

        //if only pattern is exhausted

        if(j==p.size()) return false;

        //if string is exhausted but the pattern is remaining

        if(i==s.size()){
            for(int k = j;k<p.size();k++){
                if(p[k]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        else if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] =  solve(s,p,i+1,j+1);
        }

        else if(p[j]=='*'){
            bool not_take = solve(s,p,i,j+1);
            bool take = solve(s,p,i+1,j);

            return dp[i][j] =  take || not_take;
        }
        else return dp[i][j] = false;


    }

    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        bool ans = solve(s,p,0,0);
        return ans;
        
    }
};