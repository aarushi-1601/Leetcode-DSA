class Solution {
public:
    bool check(string &s){
       int open = 0 ;
        for(int i = 0 ; i < s.length();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open<=0){
                    return false;
                }
                else{
                    open--;
                }
            }
        }
        return open==0;
    }
    vector<string> generateParenthesis(int n) {
        const int mask = 1 << 2*n ;
        vector<string> ans;
        for(int i = 0 ; i < mask  ; i++){
            string s = "";
            for(int j = 0 ; j < 2*n ; j++){
                if(i&(1<<j)){
                    s+="(";
                }
                else{
                    s+=')';
                }
            }
            cout << s << endl;
            if(check(s)){
                    ans.push_back(s);
             }
        }
        return ans;
    }
};