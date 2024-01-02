class Solution {
public:
    int longestValidParentheses(string s) {
     int max_length = 0;

        for (int i = 0; i < s.length(); i++) {
            int left_count = 0;
            int right_count = 0;

            for (int j = i; j < s.length(); j++) {
                if (s[j] == '(') {
                    left_count++;
                } else if (s[j] == ')') {
                    right_count++;
                }

                if (left_count == right_count) {
                    max_length = max(max_length, j - i + 1);
                } else if (right_count > left_count) {
                    break;
                }
            }
        }

        return max_length;
    }
};