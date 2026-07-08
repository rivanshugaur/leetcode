class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n==1) return false;
        stack<char>st;
        int i = 0;
        while(i<s.size()){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ) st.push(s[i]);
            else{
                if(st.empty()) return false;

                char ele = st.top();

                if((ele=='(' && s[i]==')') || (ele=='{' && s[i]=='}') || (ele=='[' && s[i]==']') ) st.pop();

                else return false;
            }
            i++;
        }
        return st.empty();
        //return true;
        
    }
};