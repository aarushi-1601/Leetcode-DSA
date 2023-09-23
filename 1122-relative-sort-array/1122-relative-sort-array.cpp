class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001] = {0}; 

        for (int& num : arr1)
            count[num]++;

        int i = 0;
        for (int& num : arr2) {
            while (count[num]-- > 0)
                arr1[i++] = num;
        }

        for (int j = 0; j < 1001; j++) {
            while (count[j]-- > 0) {
                arr1[i++] = j;
            }
        }

        return arr1;
    }
};