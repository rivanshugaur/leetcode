class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        
        vector<int>earliest(n);
        vector<int>latest(n);

        for(int i = 0,j=0;i<n;i++){
            while(j<m && skill[i]!=station[j]){
                j++;
            }
            earliest[i] = j++;
        }
        for(int i = n-1,j = m-1;i>=0;i--){
            while(j>=0 && skill[i]!=station[j]){
                j--;
            }
            latest[i] = j--;
        }
        int gap = 0;
        for(int i = 1;i<n;i++){
            gap = max(gap, latest[i]-earliest[i-1]);
        }
        return gap;
        
    }
};