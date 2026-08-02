class Solution {
public:

int dp[101];

int solve(string &s , int idx, string curr){
    if(idx>s.size()) return 0;
    if(stoi(curr)>26) return 0;
    if(s[idx]=='0') return 0;
    if(idx==s.size()) return 1;
    if(dp[idx]!=-1) return dp[idx];

    int take_one = solve(s,idx+1,s.substr(idx,1));
    int take_two = solve(s,idx+2,s.substr(idx,2));

    return dp[idx] =  take_one + take_two;


}

    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(s,0,s.substr(0,1));
        return ans;
        
    }
};