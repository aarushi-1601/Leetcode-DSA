class Solution {
public:
    int minimumOperations(vector<int>& arr) {
        unordered_set<int> s(arr.begin(),arr.end());
        return s.size()-s.count(0);
    }
};