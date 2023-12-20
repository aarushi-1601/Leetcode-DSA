class Solution {
public:
    static int helper2(int num){
        vector<int> dp(10005,INT_MAX-10);
        dp[0] = 0;

        for(int n=1; n<=num; n++){
            int ans = INT_MAX-10;
            for(int i=1; i*i<=n; i++){
                ans = min(ans,dp[n-i*i]+1);
            }
            dp[n] = ans;
        }
        return dp[num];
    }
    int numSquares(int n) {
        return helper2(n);
    }
};