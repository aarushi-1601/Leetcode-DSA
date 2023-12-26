class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int,int>> dup;
        for(int i =0 ; i< nums.size(); i++){
            dup.push_back(make_pair(nums[i], i));
        }
        sort(dup.begin(), dup.end());
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j<nums.size() && abs(dup[i].first-dup[j].first)<=valueDiff; j++){
                if(abs(dup[i].second - dup[j].second)<=indexDiff)
                    return true;
            }
        }
        return false;
    }
};