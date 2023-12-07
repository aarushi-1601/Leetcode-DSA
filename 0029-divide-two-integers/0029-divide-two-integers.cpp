class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long result = (long long)dividend / (long long)divisor;

        //return (int)(result > INT32_MAX ? INT32_MAX : result < INT32_MIN ? INT32_MIN : result);
        return (int)result;
    }
};
