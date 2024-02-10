class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int inc1=0;
        int  exc1=0;
          int inc2=0;
        int  exc2=0;
        if(n==1)
        return nums[0];
        //lets work on the steps where we inc the fitdt part;
        for(int i=0;i<n-1;i++)
        {
           
	       int x=exc1+nums[i];
	        exc1=max(exc1,inc1);
	        inc1=x;
        }
        int m1=max(inc1,exc1);
         for(int i=1;i<n;i++)
        {
           
	       int x=exc2+nums[i];
	        exc2=max(exc2,inc2);
	        inc2=x;
        }
        int m2=max(inc2,exc2);
        return max(m1,m2);
    }
};