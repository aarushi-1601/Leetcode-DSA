class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int l=0,h=n-1;
        int m;
        int c=0;
        if(target<nums[0])
        {
            c=1;
        }
       
        while(l<=h)
        {
            m=l+(h-l)/2;
            if(c==1)
            {
                if(nums[m]>target && nums[0]>nums[m])
                {
                    h=m-1;
                }
                else if(nums[m]>target && nums[0]<=nums[m])
                {
                    l=m+1;
                }
                else if(nums[m]==target)
                {
                    return m;
                }
                else
                {
                    l=m+1;
                }
            }
            else
            {
                if(nums[m]<target && nums[0]>nums[m])
                {
                    h=m-1;
                }
                else if(nums[m]<target && nums[0]<=nums[m])
                {
                   l=m+1; 
                }
                else if(nums[m]==target)
                {
                    return m; 
                }
                else
                {
                    h=m-1;
                }
            }
        }
        return -1;
    }
};