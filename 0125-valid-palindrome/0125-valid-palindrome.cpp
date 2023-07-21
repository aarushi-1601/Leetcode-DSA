class Solution {
public:
    bool isPalindrome(string s) {
        
         if(s.empty()) return true;
        vector<int> v;
        for (auto ch: s){
            if(isalnum(ch)){
                v.push_back(tolower(ch));
            }
        }
        int st = 0;
        int e = v.size() - 1;
        while (st < e){
            if(v[st] != v[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;       
    
    }
};


