class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = n-1;
        while(i<=j){
            if(nums[i]==val){
                swap(nums[i],nums[j]);
                
                j--;
            }
            else{
                count++;
                i++;
            }
        }
        // for(int i = 0;i<n;i++){
        //     if(nums[i]==val){
        //         nums[i] = INT_MAX;
        //     }
        //     else count++;
        // }
        // sort(nums.begin(),nums.end());
        return count;
        
    }
};