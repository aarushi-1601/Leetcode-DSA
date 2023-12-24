class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> nums_set(nums.begin(), nums.end());
        if (nums_set.size() < 3){
            return *nums_set.rbegin();
        }
        auto it = nums_set.rbegin();
        advance(it, 2);
        return *it;
    }
};