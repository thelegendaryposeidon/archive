class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        help(res,"",n,0);
        return res;
    }

    void help(vector<string>&res, string s, int n, int o){
        if(o<0){
            return;
        }
        if(s.size() == n*2){
            if(o== 0){
                res.push_back(s);
            }
        }
        else{
            help(res, s +')',n ,o-1);
            help(res, s+'(', n, o+1);
        }
    }
};