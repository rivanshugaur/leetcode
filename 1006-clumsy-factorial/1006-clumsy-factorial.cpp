class Solution {
public:
bool flag = true;
    int factorial(int n){
        //base case
        if(n==0) return 0;
        if(n==1) return -1;
        if(n==2) return -2*1;
        if(n==3) return -3*2/1;
        if(n==4) return -(4*3/2)+1;

        int ans;
        if(flag){
            ans = ((n*(n-1))/(n-2)) + (n-3);
            flag = false;
        }
        else {
            ans = ((-n*(n-1))/(n-2)) + (n-3);
        }
        return ans + factorial(n-4);
    }
    int clumsy(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2*1;
        if(n==3) return 3*2/1;
        if(n==4) return (4*3/2)+1;
       int res = factorial(n);
       return res;

        
    }
};