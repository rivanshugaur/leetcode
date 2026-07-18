class Solution {
public:
    string common(string x, string y){
        int n1 = x.size();
        int n2 = y.size();
        string ans = "";
        int i = 0;
        int j = 0;
        while(i<n1,j<n2){
            if(x[i]==y[j]){
                ans+=x[i];
            }
            else break;
            i++;
            j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1) return strs[0];
        int i = 2;
        string res = common(strs[0],strs[1]);
        while(i<n){

            res = common(res,strs[i]);
            i++;
        }
        return res;
        
    }
};