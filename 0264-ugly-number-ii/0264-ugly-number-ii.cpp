class Solution {
public:

    int nthUglyNumber(int n) {
        int ai = 0;
        int bi = 0;
        int ci = 0;
        vector<int>ans(n);
        ans[0] = 1;
        for(int i = 1;i<n;i++){
            int a = ans[ai]*2;
            int b = ans[bi]*3;
            int c = ans[ci]*5;

            ans[i] = min({a,b,c});
            if(ans[i]==a) ai++;
            if(ans[i]==b) bi++;
            if(ans[i]==c) ci++;

        }
        return ans[n-1];
        
    }
};