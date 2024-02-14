class Solution {
public:
    int MOD = 1e9+7;
    int dp[(int)(1e5 + 1)][2][3];
    int solve(int idx, int n, bool absent_taken, int cnt_late){
        if(idx>=n)return 1;
        if (dp[idx][absent_taken][cnt_late] != -1)
            return dp[idx][absent_taken][cnt_late];
        if(absent_taken==false){
            int present = solve(idx+1, n, false, 0);
            int late  = 0;
            if(cnt_late!=2){
                late = solve(idx+1, n, false, cnt_late+1);
            }
            int absent = solve(idx+1, n, true, 0);
            return dp[idx][absent_taken][cnt_late]=((present+late)%MOD+absent)%MOD;
        }
        int present = solve(idx+1, n, true, 0);
        int late = 0;
        if(cnt_late!=2){
            late = solve(idx+1, n, true, cnt_late+1);
        }

        return dp[idx][absent_taken][cnt_late] = (present+late)%MOD;
        

    }
    int checkRecord(int n) {
        // dp.clear();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, false, 0);
    }
};
