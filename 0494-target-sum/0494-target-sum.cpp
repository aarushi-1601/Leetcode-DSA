class Solution {
public:
    int f(vector<int>& nums,int target, int n, vector<vector<int>>&dp){
          if (n==0) {
            if (target==0 && nums[n]==0) return 2;
            if (nums[n]==target || target==0) return 1;
            return 0;
        }
      
      
         if(dp[n][target]!=-1)
         return dp[n][target];

        int notpick=f(nums,target,n-1,dp);
        int pick=0;
        if(nums[n]<=target){
            pick=f(nums,target-nums[n],n-1,dp);
        }
        return dp[n][target]=pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         int k=0;
        for(int i=0;i<nums.size();i++){
            k+=nums[i];
        }
        
        target=(k-target);
        if(target<0)
        return 0;
        
        vector<vector<int>>dp(nums.size(),vector<int>((target/2)+1,-1));
        if(target%2!=0)
        return 0;
        return f(nums,target/2,nums.size()-1,dp);
    }
};