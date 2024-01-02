class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char ch : s)mp[ch]++;
        int sum=0;
        int a=0;
        for(auto x : mp)
        {
            if(x.second%2==1 and x.second>2){
                sum+=x.second-1;
                a=1;
            }
            else if(x.second&1)a=1;
            else if(x.second%2==0)sum+=x.second;
        }
        return sum+a;
    }
};