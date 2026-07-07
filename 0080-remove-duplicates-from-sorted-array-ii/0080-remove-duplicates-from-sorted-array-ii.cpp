class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int i = 2;
        int j = 2;
        while(i<n){
            if(nums[i]!=nums[j-2]){
                nums[j] = nums[i];
                j++;
            }
            i++;

        }
        return j;
        
    }
};