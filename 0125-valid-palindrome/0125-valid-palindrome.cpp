class Solution {
public:
    bool isalphanum(char ele){
         if((ele>=97 && ele<=122 )|| (ele>=65 && ele<=90) || (ele>=48 && ele<=57)) return true;
         else return false;
    }
    bool isPalindrome(string s) {

        int n = s.size();
        int lo = 0;
        int hi = n-1;
        while(lo<hi){
            while(lo<hi && !isalphanum(s[lo]) ){
                lo++;
            }

            while(lo<hi && !isalphanum(s[hi])){
                hi--;
            }

            if(tolower(s[lo])==tolower(s[hi])){
                lo++;
                hi--;
            } 
            else return false;
        }
        return true;
        
    }
};