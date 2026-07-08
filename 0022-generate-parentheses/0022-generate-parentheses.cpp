class Solution {
public:
//x -> remaining open bracket
//y -> remaining closed bracket
vector<string>ans;

    void result(int x,int y, string & res){
            if(x>y) return ;
            if(x==0 && y==0){
                ans.push_back(res);
                return;
            }
            
            if(x>0){
                res.push_back('(');
                result(x-1,y,res);
                res.pop_back();

            }
            if(y>x){
                res.push_back(')');
                result(x,y-1,res);
                res.pop_back();

            }


    }

    vector<string> generateParenthesis(int n) {
        string res = "";
        result(n, n, res);
        return ans;
        
    }
};