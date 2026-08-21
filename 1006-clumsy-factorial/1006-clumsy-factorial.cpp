class Solution {
public:

    int fact(int n,bool flag){
        if(n==1) return -1;
        if(n==2) return -2;
        if(n==3) return -6;
        if(n==4) return -5;

        int x;

        if(flag){
            x = (-n*(n-1))/(n-2)+(n-3);
            return x + fact(n-4,flag);
            
        }
        else {
            x = (n*(n-1))/(n-2)+(n-3);
            return x + fact(n-4,!flag);
        }
        return 0;

        
    }

    int clumsy(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 6;
        if(n==4) return 7;
        int ans = fact(n,false);
        return ans;
        
    }
};