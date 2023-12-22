class Solution {
    const int MOD = 1e9+7;
public:
    int maximumXorProduct(long long a, long long b, int n) {
        for(int i = n-1; i >= 0; i--) {
            long long x = (1LL<<i);
            long long ax = a^x, bx = b^x;

            if((__int128)a*b < (__int128)ax*bx) {
                a = ax;
                b = bx;
            }
        }
        
        return (a%MOD)*(b%MOD)%MOD;
    }
};