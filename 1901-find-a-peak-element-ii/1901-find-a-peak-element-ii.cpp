class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int lo = 0;
        int hi = m-1;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            //find max in this column
            int maxi = INT_MIN;
            int max_idx = 0;
            for(int i = 0;i<n;i++){
                if(mat[i][mid] > maxi){
                    max_idx = i;
                    maxi = mat[i][mid];
                } 
            }
            int left = -1;
            int right = -1;
            if(mid!=0) left = mat[max_idx][mid-1];
            if(mid!=m-1) right = mat[max_idx][mid+1];

            if(mat[max_idx][mid]>left && mat[max_idx][mid] > right) return {max_idx,mid};

            if(mat[max_idx][mid] < right) lo = mid+1;
            if(mat[max_idx][mid] < left) hi = mid-1;
        }
        return{-1,-1};
        
    }
};