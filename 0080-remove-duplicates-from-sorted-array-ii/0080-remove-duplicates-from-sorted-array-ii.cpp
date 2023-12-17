class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 2)
        {
            return n;
        }
        
        int i = 0;

        int p1 = 0;
        int p2 = 0;

        while (p2 < n)
        {
            p2 = p1;
            while (nums[p2]==nums[p1])
            { 
                if (p2-p1<2)
                    nums[i++] = nums[p1];
                
                p2++;
                if (p2==n)
                {
                    break;
                }
            }
            p1 = p2;
        }

        return i;
        
    }
};