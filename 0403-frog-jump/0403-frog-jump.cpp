class Solution {
public:
    int t[2001][2001];
    int n;
    unordered_map<int,int>mp;
    bool solve(vector<int>& stones,int curr_idx, int prev_jump){
        if(curr_idx==n-1) return true;

        bool result = false;
        if(t[curr_idx][prev_jump]!=-1) return t[curr_idx][prev_jump] ;
        for(int next_jump = prev_jump-1;next_jump<=prev_jump+1;next_jump++){
            if(next_jump>0){
                if(mp.find(stones[curr_idx]+next_jump)!=mp.end()){
                    result = result || solve(stones,mp[stones[curr_idx]+next_jump],next_jump);
                }
            }
        }
        return t[curr_idx][prev_jump] =  result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1]!=1) return false;
        for(int i = 0;i<n;i++){
            mp[stones[i]] = i;
        }
        memset(t,-1,sizeof(t));
        bool flag = solve(stones,mp[0],0);
        return flag;
        
    }
};