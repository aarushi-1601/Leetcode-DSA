class Solution {
public:
    int solve(int mask, vector<string>& stickers, string target, int n, int m, vector<int>& dp) {
        if (mask == (1 << m) - 1) {
            return 0;
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }
    
        int ans = 1e9;
           
        for (int i = 0; i < n; i++) {
    
            vector<int> freq(26, 0);
            for (auto ele : stickers[i]) {
                freq[ele - 'a']++;
            }
            int new_mask = 0;
    
            for (int j = 0; j < m; j++) {
                if (((1 << j) & mask) == 0) {
                    if (freq[target[j] - 'a']) {
                        freq[target[j] - 'a']--;
                        new_mask |= (1 << j);
                    }
                }
            }
    
            if (new_mask != 0) {
                ans = min(ans, 1 + solve(new_mask | mask, stickers, target, n, m, dp));
            }
        }
    
        return dp[mask] = ans;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int mask = 0;
        int n = stickers.size();
       int m = target.size();
    
        vector<int> dp(1 << m, -1);
        int ans = solve(mask, stickers, target, n, m, dp);
        return ans == 1e9 ? -1 : ans;
    }
};