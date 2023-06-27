class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int, int> mp;
       set<int> st1;
       set<int> st;

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
            st1.insert(arr[i]);
        }

        for(auto it:mp){
            st.insert(it.second);
        }

        return st.size() == st1.size();
    }
};