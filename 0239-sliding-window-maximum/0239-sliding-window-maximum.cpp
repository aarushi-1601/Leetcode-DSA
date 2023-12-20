class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        int two_pow = 1;
        for (int dim = 0; dim < 31; dim++){
            if (two_pow >= n) break;
            two_pow = two_pow * 2;
        }
       
        vector<vector<int>> tree(1, nums);
        tree[0].resize(two_pow);
        for (int i = n; i < two_pow; i++) tree[0][i] = INT_MIN;
        while(true){
            if ((int)tree.back().size() == 1) break;
            int update_n = (int)tree.back().size() / 2;
            vector<int> update_layer(update_n);
            for (int i = 0; i < update_n; i++){
                update_layer[i] = max(tree.back()[i * 2], tree.back()[i * 2 + 1]);
            }
            tree.push_back(update_layer);
        }
        
        vector<int> ret(n - k + 1);
        for (int start = 0; start <= n - k; start++){
            int back = start + k - 1;
            ret[start] = query_max(tree, 0, start, back);
        }
        return ret;
    }
    int query_max(vector<vector<int>>& tree, int lvl, int start, int back){

        if (start == back) return tree[lvl][start];
        if (start > back) return INT_MIN;
        
        int start_val = INT_MIN;
        if (start % 2 != 0) {
            start_val = tree[lvl][start];
            start += 1;
        }
        int back_val = INT_MIN;
        if (back % 2 == 0){
            back_val = tree[lvl][back];
            back -= 1;
        }
        return max({start_val, back_val, query_max(tree, lvl + 1, start / 2, back / 2)});
    }
};