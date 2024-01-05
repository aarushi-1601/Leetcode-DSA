class Solution {
public:

int solve(vector<int>&nums){
    int n = nums.size();
    int cnt = 0;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            cnt++;
        }
       else{
         maxi = max(maxi, cnt);
         cnt = 0;
       }
    }
     maxi = max(maxi, cnt);
    if(maxi > n) return -1;

    return maxi;
}

    int findMaxConsecutiveOnes(vector<int>& nums) {
        return solve(nums);
    }
};