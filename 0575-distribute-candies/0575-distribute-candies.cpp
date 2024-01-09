class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int types_num = set<int>(candies.begin(), candies.end()).size();
        return types_num > candies.size()/2 ? candies.size()/2 : types_num;
    }
};