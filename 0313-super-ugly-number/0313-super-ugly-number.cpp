class Solution {
public:
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int k = primes.size();
    vector<int> pos(k, 0);
    vector<int> res(n);
    res[0] = 1;
    for (int i = 1; i < n; i++) {
        long temp = INT_MAX;
        for (int j = 0; j < k; j++) 
            temp = min(temp, ((long)res[pos[j]] * primes[j]));
        for (int j = 0; j < k; j++) {
            if (temp == (long)res[pos[j]] * primes[j])
                pos[j]++;
        }
        res[i] = temp;
    }
    return res[n - 1];
}
};