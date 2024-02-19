class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), ll = 0, ul = n - 1, mid = 0, ans = 0;
        while(ll <= ul){
            mid = (ll + ul) >> 1;
            int x = n - mid;
            if(x <= citations[mid]){
                ans = x;
                ul = mid - 1;
            }
            else
                ll = mid + 1;
        }
        return ans;
    }
};