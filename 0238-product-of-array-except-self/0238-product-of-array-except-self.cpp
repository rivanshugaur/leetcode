class Solution {
public:
//without using extra space
//nums = [1,2,3,4] 
//res = [24,12,4,1]
//res = [24,12,8,6]
//prev = 1->1->2->6->24
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        int prev = 1;
        for(int i = n-1;i>=0;i--){
            res[i] = prev;
            prev = nums[i]*prev;
        }
        prev = 1;
        for(int i = 0;i<n;i++){
            res[i] = res[i]*prev;
            prev = prev*nums[i];
        }
        return res;
        
    }
};