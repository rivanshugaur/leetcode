class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxi = INT_MIN;
        int n = stones.size();
        if(n==2) return stones[1]-stones[0];
        for(int i = 0;i<n-2;i++){
            int x = stones[i];
            int y = stones[i+2];
            int diff = y-x;
            maxi = max(maxi,diff);
        }
        // for(int i = 1;i<n-2;i++){
        //     int x = stones[i];
        //     int y = stones[i+2];
        //     int diff = y-x;
        //     maxi = max(maxi,diff);
        // }
        maxi = max({maxi , stones[1]-stones[0] , stones[n-1]-stones[n-2]});
        return maxi;
        
    }
};