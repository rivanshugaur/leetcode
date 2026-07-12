class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n==1) return false;
        stack<char>st;
        int i = 0;
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                if((ch=='(' && s[i]==')') || (ch=='{' && s[i]=='}') || (ch=='[' && s[i]==']') ) st.pop();
                else return false;
            }
            i++;
        }
        
        return st.empty();

        
    }
};