class Solution {
public:
    int findIntegers(int n) {
        vector<int>v;
        for(int i=0;i<31;i++){
            if(n & (1<<i)) v.push_back(1);
            else v.push_back(0);
        }
        while(v.size() and v.back()==0) v.pop_back();
        reverse(v.begin(),v.end());


        int vn = v.size();
        vector<vector<int>>dp(vn,vector<int>(2));
        dp[vn-1][0] = dp[vn-1][1] = 1;
        for(int i = vn-2;i>=0;i--){
            dp[i][0] = dp[i+1][0] + dp[i+1][1];
            dp[i][1] = dp[i+1][0];
        }

        int ans = 0;
        int i = 0;
        while(i < vn) {
            if(v[i]) {
               ans += dp[i][0];

               if(i < vn-2 and v[i+1] == 1) {
                   ans += (dp[i+2][0] + dp[i+2][1]);
                   return ans;
               }
               i+= 2;
            }
            
            else i += 1;
        }

        return ans+1;
    }
};