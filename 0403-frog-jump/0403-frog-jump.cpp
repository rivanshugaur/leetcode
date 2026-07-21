class Solution {
public:
    unordered_map<int,int>mp;
    int dp[2001][2001];// dp[idx][k]
    bool path(vector<int>& stones,int curr_sum,int k){
        if(mp.find(curr_sum)==mp.end()) return false;
        if(k<=0) return false;
        int idx = mp[curr_sum];
        if(dp[idx][k]!=-1) return dp[idx][k];
        int n = stones.size();
        if(idx == n-1) return dp[idx][k] = true;
        

        bool i = path(stones, curr_sum+k-1,k-1);//k-1
        bool j = path(stones,curr_sum+k,k);//k
        bool p = path(stones,curr_sum+k+1,k+1);//k+1

        return dp[idx][k] =  i || j || p;

    }

    bool canCross(vector<int>& stones) {
        for(int i = 0;i<stones.size();i++){
            mp[stones[i]] = i;
        }
        memset(dp,-1,sizeof(dp));
        bool ans = path(stones,1,1);
        return ans;
        
    }
};