class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return n;
        int i = 0;
        int j = 0;
        while(i<n && j<n){
            if(nums[j]==nums[i]){
                j++;
            }
            else if(nums[j]!=nums[i]){
                swap(nums[i+1],nums[j]);
                    i++;
                    j++;
                
            }
        }
        return i+1;
        
    }
};