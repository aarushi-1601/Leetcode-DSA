class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[51][51][51];
    set<vector<int>> st;
    int solve(int n, int limit, int left, int middle, int right) {
        if(left+middle+right>n) return 0;
        if (left + middle + right == n && st.count({left,middle,right})==0) {
            st.insert({left,middle,right});
            return 1;
        }

        if (memo[left][middle][right] != -1) {
            return memo[left][middle][right];
        }

        long long ways = 0;
        if (left < limit) {
            ways += solve(n, limit, left + 1, middle, right)%MOD;
        }
        if (middle < limit) {
            ways += solve(n, limit, left, middle + 1, right)%MOD;
        }
        if (right < limit) {
            ways += solve(n, limit, left, middle, right + 1)%MOD;
        }

        memo[left][middle][right] = ways;
        return ways;
    }

    int distributeCandies(int n, int limit) {
        memset(memo, -1, sizeof(memo));
        solve(n, limit, 0, 0, 0);
        return st.size();
    }
};