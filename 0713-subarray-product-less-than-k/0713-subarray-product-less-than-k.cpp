class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

    int totalCount = 0;
    int product = 1;

    // Use two pointers to maintain a sliding window
    for (int left = 0, right = 0; right < nums.size(); right++) {
      // Expand the window by including the element at the right pointer
      product *= nums[right];

      // Shrink the window from the left while the product is greater than or equal to k
      while (product >= k) {
        // Remove the element at the left pointer from the product
        product /= nums[left++];
      }

      // Update the total count by adding the number of valid subarrays with the current window size
      totalCount += right - left + 1;  // right - left + 1 represents the current window size
    }

    return totalCount;
    }
};