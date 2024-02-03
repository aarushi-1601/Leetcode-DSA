class Solution {
public:
    bool valid(string s)
    {
        int n = s.size();
        for(int i=0; i<n/2; i++)
        {
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
    void helper(int start,string &s,vector<string> &temp,vector<vector<string>> &ans)
    {
        if(start >= s.length())
        {
            ans.push_back(temp);
            return;
        }
        for(int end=start; end<s.length(); end++)
        {
            string currStr = s.substr(start,end-start+1);
            if(valid(currStr))
            {
                temp.push_back(currStr);
                helper(end+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(0,s,temp,ans);
        return ans;
    }
};