class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int count = 0;
        int n = s.size();
        int i = 0;
        int j = 0;
        int a = 0,b = 0,c = 0;
        while(i<n && j<n){
            if(s[j]=='a') a++;
            if(s[j]=='b') b++;
            if(s[j]=='c') c++;

            while(a>0 && b>0 && c>0){
                count+=n-j;
                if(s[i]=='a') a--;
                if(s[i]=='b') b--;
                if(s[i]=='c') c--;
                i++;
            }
            j++;
        }
        return count;
    }
};