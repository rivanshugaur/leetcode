class Solution {
public:

    bool check(string s){
        int n = s.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;

        }
        return true;
    }


    bool isPalindromic(string s) {

    string si="";
    int n = s.size();
    for(int i = 0;i<n;i++){
        int num = s[i];
        string temp = bitset<8>(num).to_string();
        si+=temp;
    }
    
    return check(si);

        
    }
};