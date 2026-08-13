class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        //tabulation 
        //see the memoization code for better understanding of the +1 int the prev 
        for(int i = n-1;i>=0;i--){
            for(int prev = i-1;prev>=-1;prev--){
                if(prev==-1 || nums[i]>nums[prev]){
                    int take = 1 + next[i+1];
                    int not_take = next[prev+1];
                    curr[prev+1] = max(take,not_take);
                }
                else curr[prev+1] = next[prev+1];

            }
            next = curr;
        }
        return curr[-1+1];//max lis till the -1 prev and idx 0

        
    }
};