class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0 || n==1) return n;
        int lo = 0;
        int hi = 0;
        int maxi = 0;
        unordered_map<char,int>mp;
        while(lo<n && hi<n){
            if(mp.find(s[lo])!=mp.end()){
                hi = max(hi,mp[s[lo]]+1);
            }
            mp[s[lo]] = lo;
            maxi = max(maxi,lo-hi+1);
            lo++;
        }
        return maxi;
    }
};