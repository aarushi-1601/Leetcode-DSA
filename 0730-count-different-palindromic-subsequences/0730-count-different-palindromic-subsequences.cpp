#define mod 1000000007
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = 2;
        }
        
        for(int m=2;m<n;m++){
            for(int i=0;i<n-m;i++){
                int j = i+m;
                if(s[i] != s[j]){
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
                else{
                    dp[i][j] = dp[i+1][j-1] * 2;
                    int low = i+1, high = j-1;
                    while(low <= high && s[low]!=s[j]){
                        low++;
                    }
                    while(high >= low && s[high]!=s[i]){
                        high--;
                    }
                    if(low == high){
                        
                        dp[i][j] += 1;
                    }
                    else if(low < high){
                        
                        dp[i][j] -= dp[low+1][high-1];
                    }
                    else{
                       
                        dp[i][j] += 2;
                    }
                }
                if(dp[i][j] < 0){
                    dp[i][j] = (dp[i][j] + mod)%mod;
                }
                else{
                    dp[i][j] = dp[i][j]%mod;
                }
            }
        }
        return dp[0][n-1];
    }
};