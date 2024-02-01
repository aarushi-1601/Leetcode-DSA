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
string getUniqueString(TreeNode * head){
    string temp = "";
    queue<TreeNode*> q;
    q.push(head);
    while(q.size()){
        auto it = q.front();
        q.pop();
        temp += to_string(it->val);
        if(it->left){
            q.push(it->left);
        }else{
            temp += "null";
        }
        if(it->right){
            q.push(it->right);
        }else{
            temp += "null";
        }
    }
    return temp;
 }
 TreeNode* construct_bst(vector<int> &v, unordered_set<string> &st){
    int n = v.size();
    TreeNode * head = new TreeNode(v[0]);
    for(int i = 1; i < n; i++){ 
        TreeNode * root = head;
        while(root){
            if(v[i] < root->val){
                if(!root->left && v[i] != root->val){
                    root->left = new TreeNode(v[i]);
                }
                root = root->left;
            }else{
                if(!root->right && v[i] != root->val){
                    root->right = new TreeNode(v[i]);
                }
                root = root->right;
            }
        }
    }

    string temp = getUniqueString(head);
    if(st.count(temp)){
        return NULL;
    }else{
        st.insert(temp);
    }

    return head;
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
    vector<int> v;
    vector<TreeNode*> ans;
    unordered_set<string> st;
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    do{
        TreeNode * curr = construct_bst(v, st);
        if(curr){ 
            ans.push_back(curr);
        }
    }while(next_permutation(v.begin(), v.end()));
    return ans;
    }
};