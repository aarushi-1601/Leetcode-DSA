class Solution {
public:
    int dp[1001][1001];
    bool isPalindromicIterative(string & s,int st,int e)
    {
        while(st<e)
            if(s[st++] != s[e--])
                return false;

        return true;
    }
    bool isPalindromicRecursive(string & s,int st,int e)
    {
            if(st>=e)return true;
            if(dp[st][e]!= -1)return dp[st][e];
            if(s[st]== s[e])
                return isPalindromicRecursive(s,st+1,e-1);
            return false;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int maxlen = INT_MIN;
        int st = 0;

        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                if(isPalindromicRecursive(s,i,j))
                {
                    if(j-i+1 > maxlen)
                    {
                        maxlen = j-i+1;
                        st=i;
                    }
                }
        
        return s.substr(st,maxlen);
    }
};