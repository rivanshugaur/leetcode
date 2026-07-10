class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>visited(26,0);
            for(int i = 0;i<s.size();i++){
                int idx = s[i] - 97;
                visited[idx]+=1;
            }
            for(int i = 0;i<t.size();i++){
                int idx = t[i]-97;
                visited[idx]-=1;
            }
            for(int i = 0;i<26;i++){
                if(visited[i]!=0) return false;
            }
            return true;
        
        
    }
};