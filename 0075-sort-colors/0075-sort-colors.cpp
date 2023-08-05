class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index=0;
        int z=0,o=0,t=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)z++;
            if(nums[i]==1)o++;
            if(nums[i]==2)t++;
        }
        
        while(z!=0)
        {
          nums[index++]=0;
          z--;
        }
        while(o!=0)
        {
          nums[index++]=1;
          o--;
        }
        while(t!=0)
        {
          nums[index++]=2;
          t--;
        }
    }
};