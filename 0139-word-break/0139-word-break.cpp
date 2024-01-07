class Solution {
public:
    set<string>dict;
    map<string,bool>dp;
    bool f(string s){
        if(s.length()==0) return true;
         
        if(dp.find(s)!=dp.end())     return dp[s];
     
       for(int i=0;i<s.length();i++){
           string r = s.substr(0,i+1);
           if(dict.count(r)){
               if(f(s.substr(i+1))){
                   return dp[s]=true;
               }
           }
       }

       return dp[s]=false;
         
          

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto it : wordDict){
            dict.insert(it);
        }
        return f(s);
    }
};