class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        int ans = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i-1][j-1] == '0'){
                    continue;
                }
                int cnt = dp[i-1][j-1];

                int x, y;
                for(x = 1; x < cnt+1; x++){
                    if(matrix[i-1-x][j-1] != '1') break;
                }
                for(y = 1; y < cnt + 1; y++){
                    if(matrix[i-1][j-1-y] != '1') break;
                }
                x--, y--;
                if(min(x, y) == cnt) dp[i][j] = cnt+1;
                else dp[i][j] = min(x, y)+1;

                ans = max(ans, dp[i][j]);
            }
        }
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return ans*ans;
    }
};