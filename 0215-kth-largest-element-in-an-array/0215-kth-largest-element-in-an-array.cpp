class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;//by default it is max head
        //to make it min heap use greater<int>

        for(auto ele: nums){
            pq.push(ele);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        
    }
};
//time complexity nlog(k)