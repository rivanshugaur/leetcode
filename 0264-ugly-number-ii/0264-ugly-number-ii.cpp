class Solution {
public:

    int nthUglyNumber(int n) {
        if(n==1) return 1;
      
        priority_queue<long long,vector<long long>, greater<long long>> minheap;
        unordered_set<long long> st;
        vector<long long> ans;
        minheap.push(1);
        for(int i = 1;i<=n;i++){

            long long mini = minheap.top();
            minheap.pop();
            ans.push_back(mini);

            long long a = mini*2;
            long long b = mini*3;
            long long c = mini*5;

            if(st.find(a)==st.end()){
                st.insert(a);
                minheap.push(a);
            }
            if(st.find(b)==st.end()){
                st.insert(b);
                minheap.push(b);
            }
            if(st.find(c)==st.end()){
                st.insert(c);
                minheap.push(c);
            }
        }
        return ans[n-1];
        
    }
};