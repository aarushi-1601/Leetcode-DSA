class Solution {
public:
    int trap(vector<int>& height) {
	int n = height.size();
	vector<int> left(n), right(n);
	left[0] = height[0];
	right[n-1] = height[n-1];
	
	for(int i=1, j=n-2; i<n; i++, j--) {
		left[i] = max(left[i-1], height[i]);
		right[j] = max(right[j+1], height[j]);
	}

	int water = 0;
	for(int i=0; i<n; i++){
		water += abs(min(left[i], right[i]) - height[i]);
	}
	
	return water;
}
};