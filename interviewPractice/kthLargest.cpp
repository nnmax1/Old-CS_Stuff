//kth largest element problem from code signal

#include <algorithm>
#include<vector>

int kthLargestElement(std::vector<int> nums, int k) {
   std::sort(nums.begin(), nums.end());
   int n = nums.size();
   return nums[n-k];
}

