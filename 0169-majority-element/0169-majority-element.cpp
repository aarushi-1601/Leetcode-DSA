class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m=INT_MIN;
        int count=0;
        for(auto e:nums){
            if(m==e)count++;
            else if(count==0)m=e;
            else count--;
        }
        return m;
    }
};