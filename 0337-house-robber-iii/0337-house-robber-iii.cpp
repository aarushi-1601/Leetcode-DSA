/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root,unordered_map<TreeNode*,int>&mp){
        if(root == NULL) return 0;
        if(mp.find(root) != mp.end()) return mp[root];
        int ans = root->val;
        if(root->left){
            ans+=find(root->left->left,mp)+find(root->left->right,mp);
        }
        if(root->right){
            ans+=find(root->right->left,mp)+find(root->right->right,mp);
        }
        ans = max(ans,find(root->left,mp)+find(root->right,mp));
        return mp[root] = ans;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        return find(root,mp);
    }
};