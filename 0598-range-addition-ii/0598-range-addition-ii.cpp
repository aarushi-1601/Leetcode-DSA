class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m;
        int b = n;
        for (auto i: ops){
            if (i[0] < a){
                a = i[0];
            }
            if (i[1] < b){
                b = i[1];
            } 
        }
        return (a * b);
        
        
    }
};