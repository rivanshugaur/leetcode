class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(int i = 0;i<t.size();i++){
            mp[t[i]]++;
        }
        int n = s.size();
        int i = 0;
        int j = 0;
        int min_i = 0;
        int min_j = n-1;
        int req_count = t.size();
        bool flag = false;
        while(i<n && j<n){
            if(mp[s[j]]>0){
                req_count--;
            }
            mp[s[j]]--;
            while(req_count==0){
                flag = true;
                if((j-i) < (min_j - min_i)){
                    min_j = j;
                    min_i = i;
                }
                if(mp[s[i]]==0) req_count++;

                mp[s[i]]++;
                i++;
            }

            
            j++;
        }
        string ans = "";
        if(flag==false) return ans;
        for(int temp = min_i;temp<=min_j;temp++){
            ans+=s[temp];
        }
        return ans;
        
    }
};