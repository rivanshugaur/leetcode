class Solution {
public:
    int partition(vector<int>& nums,int left , int right){
        if(left>right) return -1;
        int pivot = nums[left];
        int i = left+1;
        int j = right;

        while(i<=j){
            if(nums[i]<pivot && nums[j]>pivot){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=pivot){
                i++;
            }
            if(nums[j]<=pivot){
                j--;
            }
            
        }
        swap(nums[left],nums[j]);
        return  j;// pivot is at the jth index
    }


    int findKthLargest(vector<int>& nums, int k) {

        int l = 0;
        int r = nums.size()-1;
        int pivot_idx = 0;
        while(true){
            pivot_idx=partition(nums,l,r);
            if(pivot_idx==k-1){
                break;
            }
            else if(pivot_idx>k-1){
                r = pivot_idx-1;
            }
            else{
                l = pivot_idx+1;
            }
            
        }
        return nums[pivot_idx];

        
    }
};